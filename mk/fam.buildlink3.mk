# $NetBSD: fam.buildlink3.mk,v 1.7 2009/03/17 14:45:19 jmcneill Exp $
#
# This Makefile fragment is meant to be included by packages that
# require a FAM implementation.  fam.buildlink3.mk will:
#
#	* set FAMBASE to the base directory of the FAM files;
#	* set FAM_TYPE to the FAM implementation used.
#
# There are three variables that can be used to tweak the selection of
# the FAM implementation:
#
# FAM_DEFAULT is a user-settable variable whose value is the default
#	FAM implementation to use.
#
# FAM_ACCEPTED is a package-settable list of FAM implementations that
#	may be used by the package.
#
# FAM_SERVER is a package-settable flag whose value determines whether
#	or not the server and library are both required.

MK_FAM_BUILDLINK3_MK:=	${MK_FAM_BUILDLINK3_MK}+

.include "../../mk/bsd.prefs.mk"

.if !empty(MK_FAM_BUILDLINK3_MK:M+)
FAM_DEFAULT?=	fam
FAM_ACCEPTED?=	${_FAM_PKGS}

# This is an exhaustive list of all of the FAM implementations that may
# be used with fam.buildlink3.mk, in order of precedence.
#
_FAM_PKGS?=	fam gamin

_FAM_DEFAULT=	${FAM_DEFAULT}
_FAM_ACCEPTED=	${FAM_ACCEPTED}

_FAM_TYPE?=	${_FAM_DEFAULT}

.  if !empty(_FAM_ACCEPTED:M${_FAM_TYPE})
FAM_TYPE=	${_FAM_TYPE}
.  else
FAM_TYPE=	none
.  endif
FAMBASE=	${BUILDLINK_PREFIX.${FAM_TYPE}}

BUILD_DEFS+=		FAM_DEFAULT
BUILD_DEFS_EFFECTS+=	FAMBASE FAM_TYPE
.endif	# MK_FAM_BUILDLINK3_MK

FAM_SERVER?=	yes

.if ${FAM_TYPE} == "none"
PKG_FAIL_REASON=	\
	"${_FAM_TYPE} is not an acceptable FAM type for ${PKGNAME}."
.elif ${FAM_TYPE} == "fam"
.  include "../../sysutils/fam/buildlink3.mk"
.elif ${FAM_TYPE} == "gamin"
.  include "../../sysutils/libgamin/buildlink3.mk"
.  if !empty(FAM_SERVER:M[Yy][Ee][Ss])
DEPENDS+=	gamin>=0.1.10nb1:../../sysutils/gamin
.  endif
.endif
