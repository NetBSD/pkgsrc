# $NetBSD: fam.buildlink3.mk,v 1.3 2005/08/29 23:16:33 jlam Exp $
#
# This Makefile fragment is meant to be included by packages that
# require a FAM implementation.  fam.buildlink3.mk will:
#
#	* set FAMBASE to the base directory of the FAM files;
#	* set FAM_TYPE to the FAM implementation used.
#
# There are two variables that can be used to tweak the selection of
# the FAM implementation:
#
# FAM_DEFAULT is a user-settable variable whose value is the default
#	FAM implementation to use.
#
# FAM_ACCEPTED is a package-settable list of FAM implementations that
#	may be used by the package.

MK_FAM_BUILDLINK3_MK:=	${MK_FAM_BUILDLINK3_MK}+

.include "../../mk/bsd.prefs.mk"

.if !empty(MK_FAM_BUILDLINK3_MK:M+)
FAM_DEFAULT?=	fam
FAM_ACCEPTED?=	${_FAM_PKGS}

# This is an exhaustive list of all of the FAM implementations that may
# be used with fam.buildlink3.mk, in order of precedence.
#
_FAM_PKGS?=	fam # XXX gamin

_FAM_DEFAULT=	${FAM_DEFAULT}
_FAM_ACCEPTED=	${FAM_ACCEPTED}

_FAM_TYPE?=	${_FAM_DEFAULT}

.  if !empty(_FAM_ACCEPTED:M${_FAM_TYPE})
FAM_TYPE=	${_FAM_TYPE}
.  else
FAM_TYPE=	none
.  endif
FAMBASE=	${BUILDLINK_PREFIX.${FAM_TYPE}}

BUILD_DEFS+=	FAM_TYPE
BUILD_DEFS+=	FAMBASE
.endif	# MK_FAM_BUILDLINK3_MK

.if ${FAM_TYPE} == "none"
PKG_FAIL_REASON=	\
	"${_FAM_TYPE} is not an acceptable FAM type for ${PKGNAME}."
.elif ${FAM_TYPE} == "fam"
.  include "../../sysutils/fam/buildlink3.mk"
.elif ${FAM_TYPE} == "gamin"
.  include "../../sysutils/gamin/buildlink3.mk"
.endif
