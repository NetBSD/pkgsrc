# $NetBSD: buildlink3.mk,v 1.72 2025/10/23 20:37:23 wiz Exp $

BUILDLINK_TREE+=	cairo

.if !defined(CAIRO_BUILDLINK3_MK)
CAIRO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.0.0nb2
BUILDLINK_ABI_DEPENDS.cairo+=	cairo>=1.18.4nb2
BUILDLINK_PKGSRCDIR.cairo=	../../graphics/cairo

.include "../../mk/bsd.fast.prefs.mk"

pkgbase := cairo
.include "../../mk/pkg-build-options.mk"

.if ${PKG_BUILD_OPTIONS.cairo:Mlzo}
.include "../../archivers/lzo/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.cairo:Mxcb}
.include "../../x11/libxcb/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.cairo:Mx11} || ${PKG_BUILD_OPTIONS.cairo:Mxcb}
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.endif

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
BUILDLINK_API_DEPENDS.pixman+=	pixman>=0.40.0
.include "../../x11/pixman/buildlink3.mk"
.endif # CAIRO_BUILDLINK3_MK

BUILDLINK_TREE+=	-cairo
