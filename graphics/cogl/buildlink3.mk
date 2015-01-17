# $NetBSD: buildlink3.mk,v 1.3 2015/01/17 14:28:51 prlw1 Exp $
#

BUILDLINK_TREE+=	cogl

.if !defined(COGL_BUILDLINK3_MK)
COGL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cogl+=	cogl>=1.14.0
BUILDLINK_ABI_DEPENDS.cogl+=	cogl>=1.18.2nb1
BUILDLINK_PKGSRCDIR.cogl?=	../../graphics/cogl

.include "../../devel/glib2/buildlink3.mk"
#.include "../../devel/pango/buildlink3.mk"
#.include "../../graphics/cairo/buildlink3.mk"

pkgbase := cogl
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.cogl:Mx11)
#.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXdamage/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../x11/libXcomposite/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.endif
.endif	# COGL_BUILDLINK3_MK

BUILDLINK_TREE+=	-cogl
