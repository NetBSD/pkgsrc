# $NetBSD: pam.buildlink3.mk,v 1.11 2009/03/20 19:25:01 joerg Exp $
#
# This Makefile fragment is meant to be included by packages that
# require a PAM implementation.
#
# User-settable variables:
#
# PAM_DEFAULT
#	The preferred PAM implementation.
#
#	Possible: linux-pam openpam solaris-pam
#	Default: (from the base system, fallback: linux-pam)
#
# Package-settable variables:
#
# PAM_ACCEPTED
#	The PAM implementations that this package can use.
#
#	Possible: (see PAM_DEFAULT)
#	Default: all
#
# System-provided variables:
#
# PAM_TYPE
#	The PAM implementation that will be used for this package.
#
# PAMBASE
#	The directory where the PAM implementation is installed.
#

PAM_BUILDLINK3_MK:=	${PAM_BUILDLINK3_MK}+

.include "bsd.fast.prefs.mk"

.if !empty(PAM_BUILDLINK3_MK:M+)
#
# This is an exhaustive list of all of the PAM implementations
# that may be used with PAM.buildlink3.mk, in order of precedence.
#
# OS conditionals can exclude implementations not available on
# some platforms.
#
.if ${OPSYS} != "Interix"
_PAM_PKGS+=	linux-pam
.endif

.if ${OPSYS} != "Interix"
_PAM_PKGS+=	openpam
.endif

# builtin only, so no conditional needed
_PAM_PKGS+=	solaris-pam

BUILDLINK_BUILTIN_MK.linux-pam=		../../security/PAM/builtin.mk
BUILDLINK_BUILTIN_MK.openpam=		../../security/openpam/builtin.mk
BUILDLINK_BUILTIN_MK.solaris-pam=	../../mk/solaris-pam.builtin.mk

# If we have a particular PAM implementation in the base system, then
# default to using that PAM type.  Otherwise, default to "linux-pam".
#
.  for _pam_ in ${_PAM_PKGS}
.    if exists(${BUILDLINK_BUILTIN_MK.${_pam_}})
CHECK_BUILTIN.${_pam_}:=	yes
.      include "${BUILDLINK_BUILTIN_MK.${_pam_}}"
.      if defined(IS_BUILTIN.${_pam_}) && \
		!empty(IS_BUILTIN.${_pam_}:M[yY][eE][sS])
PAM_DEFAULT?=	${_pam_}
.      endif
CHECK_BUILTIN.${_pam_}:=	no
.    endif
.  endfor
PAM_DEFAULT?=	linux-pam
PAM_ACCEPTED?=	${_PAM_PKGS}

_PAM_DEFAULT=	${PAM_DEFAULT}
_PAM_ACCEPTED=	${PAM_ACCEPTED}

_PAM_TYPE?=	${_PAM_DEFAULT}

.  if !empty(_PAM_ACCEPTED:M${_PAM_TYPE})
PAM_TYPE=	${_PAM_TYPE}
.  else
PAM_TYPE=	none
.  endif
PAMBASE=	${BUILDLINK_PREFIX.${PAM_TYPE}}

BUILD_DEFS+=		PAM_DEFAULT
BUILD_DEFS_EFFECTS+=	PAMBASE PAM_TYPE
.endif	# PAM_BUILDLINK3_MK

.if ${PAM_TYPE} == "none"
PKG_FAIL_REASON=	\
	"${_PAM_TYPE} is not an acceptable PAM type for ${PKGNAME}."
.elif ${PAM_TYPE} == "linux-pam"
.  include "../../security/PAM/buildlink3.mk"
.elif ${PAM_TYPE} == "openpam"
.  include "../../security/openpam/buildlink3.mk"
.elif ${PAM_TYPE} == "solaris-pam"
BUILDLINK_TREE+=	solaris-pam -solaris-pam
.endif
