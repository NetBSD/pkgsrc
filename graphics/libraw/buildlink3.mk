# $NetBSD: buildlink3.mk,v 1.8 2019/07/16 15:45:03 nia Exp $

BUILDLINK_TREE+=	libraw

.if !defined(LIBRAW_BUILDLINK3_MK)
LIBRAW_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libraw+=	libraw>=0.16.0
BUILDLINK_ABI_DEPENDS.libraw+=	libraw>=0.19.3
BUILDLINK_PKGSRCDIR.libraw?=	../../graphics/libraw

.include "../../mk/pkg-build-options.mk"
.if !empty(PKG_BUILD_OPTIONS.libraw:Mjasper)
.  include "../../graphics/jasper/buildlink3.mk"
.endif
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.endif	# LIBRAW_BUILDLINK3_MK

BUILDLINK_TREE+=	-libraw
