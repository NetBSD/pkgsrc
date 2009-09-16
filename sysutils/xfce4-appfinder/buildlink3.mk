# $NetBSD: buildlink3.mk,v 1.20 2009/09/16 01:15:34 reed Exp $

BUILDLINK_TREE+=	xfce4-appfinder

.if !defined(XFCE4_APPFINDER_BUILDLINK3_MK)
XFCE4_APPFINDER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xfce4-appfinder+=	xfce4-appfinder>=4.6.0
BUILDLINK_PKGSRCDIR.xfce4-appfinder?=	../../sysutils/xfce4-appfinder

.endif # XFCE4_APPFINDER_BUILDLINK3_MK

BUILDLINK_TREE+=	-xfce4-appfinder
