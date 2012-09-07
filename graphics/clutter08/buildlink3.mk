# $NetBSD: buildlink3.mk,v 1.11 2012/09/07 19:16:42 adam Exp $
#

BUILDLINK_TREE+=	clutter08

.if !defined(CLUTTER08_BUILDLINK3_MK)
CLUTTER08_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.clutter08+=	clutter08>=0.8.0
BUILDLINK_ABI_DEPENDS.clutter08+=	clutter08>=0.8.8nb10
BUILDLINK_PKGSRCDIR.clutter08?=	../../graphics/clutter08

pkgbase := clutter08
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.clutter08:Mx11)
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXdamage/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../x11/libXcomposite/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.endif # CLUTTER08_BUILDLINK3_MK

BUILDLINK_TREE+=	-clutter08
