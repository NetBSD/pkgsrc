# $NetBSD: mesa.buildlink3.mk,v 1.1 2026/11/25 14:41:30 wiz Exp $
#
# This Makefile fragment is meant to be included by packages that
# require a Mesa implementation.  mesa.buildlink3.mk will:
#
#	* set MESABASE to the base directory of the Mesa files;
#	* set MESA_TYPE to the Mesa implementation used.
#
# There are two variables that can be used to tweak the selection of
# the Mesa implementation:
#
# MESA_DEFAULT is a user-settable variable whose value is the default
#	Mesa implementation to use.
#
# MESA_ACCEPTED is a package-settable list of Mesa implementations
#	that may be used by the package.
#
# The allowed values are: mesa MesaLib

MK_MESA_BUILDLINK3_MK:=	${MK_MESA_BUILDLINK3_MK}+

.include "bsd.fast.prefs.mk"

.if !empty(MK_MESA_BUILDLINK3_MK:M+)

# This is an exhaustive list of all of the Mesa implementations
# that may be used with mesa.buildlink3.mk, in order of precedence.
#
_MESA_PKGS?=	MesaLib mesa

MESA_ACCEPTED?=	${_MESA_PKGS}

_MESA_DEFAULT=	${MESA_DEFAULT}
_MESA_ACCEPTED=	${MESA_ACCEPTED}

_MESA_TYPE?=	${_MESA_DEFAULT}

.  if !empty(_MESA_ACCEPTED:M${_MESA_TYPE})
MESA_TYPE=	${_MESA_TYPE}
.  else
MESA_TYPE=	none
.  endif

BUILD_DEFS+=		MESA_DEFAULT
BUILD_DEFS_EFFECTS+=	MESABASE MESA_TYPE

MESABASE=	${BUILDLINK_PREFIX.${MESA_TYPE}}

.endif	# MK_MESA_BUILDLINK3_MK

# Include the bl3 files outside the multiple-include protection.  They
# should get into the buildlink tree each time this file is included,
# not just the first time.

.if ${MESA_TYPE} == "none"
PKG_FAIL_REASON+=	\
	"${_MESA_TYPE} is not an acceptable Mesa type for ${PKGNAME}."
.elif ${MESA_TYPE} == "MesaLib"
.  include "../../graphics/MesaLib/buildlink3.mk"
.elif ${MESA_TYPE} == "mesa"
.  include "../../graphics/mesa/buildlink3.mk"
.endif
