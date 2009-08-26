# $NetBSD: buildlink3.mk,v 1.5 2009/08/26 19:57:06 sno Exp $

BUILDLINK_TREE+=	xfce4-mousepad

.if !defined(XFCE4_MOUSEPAD_BUILDLINK3_MK)
XFCE4_MOUSEPAD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xfce4-mousepad+=	xfce4-mousepad>=0.2.14nb1
BUILDLINK_ABI_DEPENDS.xfce4-mousepad?=	xfce4-mousepad>=0.2.14nb2
BUILDLINK_PKGSRCDIR.xfce4-mousepad?=	../../editors/xfce4-mousepad

.include "../../x11/libxfce4gui/buildlink3.mk"
.include "../../devel/xfce4-dev-tools/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.endif # XFCE4_MOUSEPAD_BUILDLINK3_MK

BUILDLINK_TREE+=	-xfce4-mousepad
