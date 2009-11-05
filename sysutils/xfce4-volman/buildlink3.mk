# $NetBSD: buildlink3.mk,v 1.1 2009/11/05 20:15:40 reinoud Exp $

BUILDLINK_TREE+=	xfce4-volman

.if !defined(XFCE4_VOLMAN_BUILDLINK3_MK)
XFCE4_VOLMAN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xfce4-volman+=	xfce4-volman>=0.2.0nb2
BUILDLINK_PKGSRCDIR.xfce4-volman?=	../../sysutils/xfce4-volman

.endif # XFCE4_VOLMAN_BUILDLINK3_MK

BUILDLINK_TREE+=	-xfce4-volman
