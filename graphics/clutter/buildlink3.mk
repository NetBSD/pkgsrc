# $NetBSD: buildlink3.mk,v 1.3 2009/06/14 22:58:01 joerg Exp $
#

BUILDLINK_TREE+=	clutter

.if !defined(CLUTTER_BUILDLINK3_MK)
CLUTTER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.clutter+=	clutter>=0.8.0
BUILDLINK_PKGSRCDIR.clutter?=	../../graphics/clutter

pkgbase := clutter
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.clutter:Mx11)
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
.endif # CLUTTER_BUILDLINK3_MK

BUILDLINK_TREE+=	-clutter
