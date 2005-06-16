# $NetBSD: pam.buildlink3.mk,v 1.5 2005/06/16 17:40:56 salo Exp $
#
# This Makefile fragment is meant to be included by packages that
# require a PAM implementation.  pam.buildlink3.mk will:
#
#	* set PAMBASE to the base directory of the PAM files;
#	* set PAM_TYPE to the PAM implementation used.
#
# There are two variables that can be used to tweak the selection of
# the PAM implementation:
#
# PAM_DEFAULT is a user-settable variable whose value is the default
#	PAM implementation to use.
#
# PAM_ACCEPTED is a package-settable list of PAM implementations
#	that may be used by the package.
#

PAM_BUILDLINK3_MK:=	${PAM_BUILDLINK3_MK}+

.include "../../mk/bsd.prefs.mk"

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

BUILD_DEFS+=	PAM_TYPE
BUILD_DEFS+=	PAMBASE
.endif	# PAM_BUILDLINK3_MK

.if ${PAM_TYPE} == "none"
PKG_FAIL_REASON=	\
	"${_PAM_TYPE} is not an acceptable PAM type for ${PKGNAME}."
.elif ${PAM_TYPE} == "linux-pam"
.  include "../../security/PAM/buildlink3.mk"
.elif ${PAM_TYPE} == "openpam"
.  include "../../security/openpam/buildlink3.mk"
.elif ${PAM_TYPE} == "solaris-pam"
BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nsolaris-pam}
BUILDLINK_PACKAGES+=	solaris-pam
.endif
