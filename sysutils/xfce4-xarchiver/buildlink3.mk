# $NetBSD: buildlink3.mk,v 1.17 2012/09/15 10:06:35 obache Exp $

BUILDLINK_TREE+=	xfce4-xarchiver

.if !defined(XFCE4_XARCHIVER_BUILDLINK3_MK)
XFCE4_XARCHIVER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xfce4-xarchiver+=	xfce4-xarchiver>=0.5.2nb1
BUILDLINK_ABI_DEPENDS.xfce4-xarchiver+=	xfce4-xarchiver>=0.5.2nb13
BUILDLINK_PKGSRCDIR.xfce4-xarchiver?=	../../sysutils/xfce4-xarchiver

.include "../../x11/libxfce4gui/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.endif # XFCE4_XARCHIVER_BUILDLINK3_MK

BUILDLINK_TREE+=	-xfce4-xarchiver
