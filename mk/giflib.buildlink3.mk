# $NetBSD: giflib.buildlink3.mk,v 1.2 2013/06/01 19:44:53 rillig Exp $

# choose a GIF library implementation:
# "libungif" was used to avoid patent problems. The patents are
# expired, so "giflib" should be safe to use.

.if !defined(MK_GIFLIB_BUILDLINK3_MK)
MK_GIFLIB_BUILDLINK3_MK=	#defined

.include "../../mk/bsd.prefs.mk"
GIFLIB_IMPLEMENTATION?= giflib
BUILD_DEFS+=	GIFLIB_IMPLEMENTATION

.if ${GIFLIB_IMPLEMENTATION} == "giflib"
.  include "../../graphics/giflib/buildlink3.mk"
.elif ${GIFLIB_IMPLEMENTATION} == "libungif"
.  include "../../graphics/libungif/buildlink3.mk"
.else
PKG_FAIL_REASON= \
	"\"${GIFLIB_IMPLEMENTATION}\" is invalid giflib in ${PKGNAME}."
.endif

.endif #MK_GIFLIB_BUILDLINK3_MK
