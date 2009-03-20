# $NetBSD: buildlink3.mk,v 1.18 2009/03/20 19:25:26 joerg Exp $

BUILDLINK_TREE+=	xfce4-appfinder

.if !defined(XFCE4_APPFINDER_BUILDLINK3_MK)
XFCE4_APPFINDER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xfce4-appfinder+=	xfce4-appfinder>=4.4.3nb1
BUILDLINK_PKGSRCDIR.xfce4-appfinder?=	../../sysutils/xfce4-appfinder

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/libxfce4gui/buildlink3.mk"
.include "../../devel/xfce4-dev-tools/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.endif # XFCE4_APPFINDER_BUILDLINK3_MK

BUILDLINK_TREE+=	-xfce4-appfinder
