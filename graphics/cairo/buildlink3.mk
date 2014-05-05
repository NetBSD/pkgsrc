# $NetBSD: buildlink3.mk,v 1.51 2014/05/05 00:47:54 ryoon Exp $

BUILDLINK_TREE+=	cairo

.if !defined(CAIRO_BUILDLINK3_MK)
CAIRO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.0.0nb2
BUILDLINK_ABI_DEPENDS.cairo+=	cairo>=1.12.16nb2
BUILDLINK_PKGSRCDIR.cairo?=	../../graphics/cairo

BUILDLINK_API_DEPENDS.Xrender+=	Xrender>=0.8
BUILDLINK_API_DEPENDS.pixman+=	pixman>=0.22.0

.include "../../mk/bsd.fast.prefs.mk"

pkgbase := cairo
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.cairo:Mxcb)
.include "../../x11/libxcb/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.cairo:Mx11)
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.endif

.include "../../archivers/lzo/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/pixman/buildlink3.mk"
.endif # CAIRO_BUILDLINK3_MK

BUILDLINK_TREE+=	-cairo
