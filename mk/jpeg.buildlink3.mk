# $NetBSD: jpeg.buildlink3.mk,v 1.5 2022/07/14 23:45:48 dholland Exp $
#
# This Makefile fragment is meant to be included by packages that
# require a libjpeg implementation.  jpeg.buildlink3.mk will:
#
#	* set JPEGBASE to the base directory of the libjpeg files;
#	* set JPEG_TYPE to the libjpeg implementation used.
#
# There are two variables that can be used to tweak the selection of
# the libjpeg implementation:
#
# JPEG_DEFAULT is a user-settable variable whose value is the default
#	libjpeg implementation to use.
#
# JPEG_ACCEPTED is a package-settable list of libjpeg implementations
#	that may be used by the package.
#
# The allowed values are: jpeg libjpeg-turbo

MK_JPEG_BUILDLINK3_MK:=	${MK_JPEG_BUILDLINK3_MK}+

.include "bsd.fast.prefs.mk"

.if !empty(MK_JPEG_BUILDLINK3_MK:M+)

# This is an exhaustive list of all of the libjpeg implementations
# that may be used with jpeg.buildlink3.mk, in order of precedence.
#
_JPEG_PKGS?=	jpeg libjpeg-turbo

JPEG_DEFAULT?=	jpeg
JPEG_ACCEPTED?=	${_JPEG_PKGS}

_JPEG_DEFAULT=	${JPEG_DEFAULT}
_JPEG_ACCEPTED=	${JPEG_ACCEPTED}

_JPEG_TYPE?=	${_JPEG_DEFAULT}

.  if !empty(_JPEG_ACCEPTED:M${_JPEG_TYPE})
JPEG_TYPE=	${_JPEG_TYPE}
.  else
JPEG_TYPE=	none
.  endif

BUILD_DEFS+=		JPEG_DEFAULT
BUILD_DEFS_EFFECTS+=	JPEGBASE JPEG_TYPE

JPEGBASE=	${BUILDLINK_PREFIX.${JPEG_TYPE}}

.endif	# MK_JPEG_BUILDLINK3_MK

# Include the bl3 files outside the multiple-include protection.  They
# should get into the buildlink tree each time this file is included,
# not just the first time.

.if ${JPEG_TYPE} == "none"
PKG_FAIL_REASON+=	\
	"${_JPEG_TYPE} is not an acceptable libjpeg type for ${PKGNAME}."
.elif ${JPEG_TYPE} == "jpeg"
.  include "../../graphics/jpeg/buildlink3.mk"
.elif ${JPEG_TYPE} == "libjpeg-turbo"
.  include "../../graphics/libjpeg-turbo/buildlink3.mk"
.endif
