# $NetBSD: pam.buildlink3.mk,v 1.12 2014/06/10 13:52:57 joerg Exp $
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
#	Default: (from the base system, fallback: openpam)
#
# Package-settable variables:
#
# System-provided variables:
#
# PAMBASE
#	The directory where the PAM implementation is installed.
#

PAM_BUILDLINK3_MK:=	${PAM_BUILDLINK3_MK}+

.include "bsd.fast.prefs.mk"

.if !empty(PAM_BUILDLINK3_MK:M+)
#
# This is an exhaustive list of all of the PAM implementations
# that may be used with pam.buildlink3.mk, in order of precedence.

_PAM_PKGS=	openpam linux-pam solaris-pam

BUILDLINK_BUILTIN_MK.linux-pam=		../../mk/linux-pam.builtin.mk
BUILDLINK_BUILTIN_MK.openpam=		../../security/openpam/builtin.mk
BUILDLINK_BUILTIN_MK.solaris-pam=	../../mk/solaris-pam.builtin.mk

# If we have a particular PAM implementation in the base system, then
# default to using that PAM type.  Otherwise, default to "openpam".
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
PAM_DEFAULT?=	openpam

PAMBASE=	${BUILDLINK_PREFIX.${PAM_DEFAULT}}

BUILD_DEFS+=		PAM_DEFAULT
BUILD_DEFS_EFFECTS+=	PAMBASE
.endif	# PAM_BUILDLINK3_MK

.if ${PAM_DEFAULT} == "openpam"
.include "../../security/openpam/buildlink3.mk"
.elif ${PAM_DEFAULT} == "linux-pam"
BUILDLINK_TREE+=	linux-pam -linux-pam
.elif ${PAM_DEFAULT} == "solaris-pam"
BUILDLINK_TREE+=	solaris-pam -solaris-pam
.endif
