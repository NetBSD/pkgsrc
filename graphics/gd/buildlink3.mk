# $NetBSD: buildlink3.mk,v 1.45 2020/03/23 07:10:53 adam Exp $

BUILDLINK_TREE+=	gd

.if !defined(GD_BUILDLINK3_MK)
GD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gd+=	gd>=2.0.15nb1
BUILDLINK_ABI_DEPENDS.gd+=	gd>=2.2.5nb2
BUILDLINK_PKGSRCDIR.gd?=	../../graphics/gd

.include "../../mk/bsd.fast.prefs.mk"

pkgbase := gd
.include "../../mk/pkg-build-options.mk"

.if ${PKG_BUILD_OPTIONS.gd:Mtiff}
.include "../../graphics/tiff/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.gd:Mx11}
.include "../../x11/libXpm/buildlink3.mk"
.endif

.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/libimagequant/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif # GD_BUILDLINK3_MK

BUILDLINK_TREE+=	-gd
