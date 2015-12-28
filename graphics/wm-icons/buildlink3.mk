# $NetBSD: buildlink3.mk,v 1.1 2015/12/28 15:08:54 tsutsui Exp $

BUILDLINK_TREE+=	wm-icons

.if !defined(WM_ICONS_BUILDLINK3_MK)
WM_ICONS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.wm-icons+=	wm-icons>=0.4.0
BUILDLINK_PKGSRCDIR.wm-icons?=	../../graphics/wm-icons
.endif	# WM_ICONS_BUILDLINK3_MK

BUILDLINK_TREE+=	-wm-icons
