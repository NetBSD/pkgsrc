# $NetBSD: buildlink3.mk,v 1.2 2020/03/08 16:48:13 wiz Exp $

BUILDLINK_TREE+=	upower

.if !defined(UPOWER_BUILDLINK3_MK)
UPOWER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.upower+=	upower>=0.99.2
BUILDLINK_ABI_DEPENDS.upower?=	upower>=0.99.4nb5
BUILDLINK_PKGSRCDIR.upower?=	../../sysutils/upower

.include "../../devel/glib2/buildlink3.mk"
.endif	# UPOWER_BUILDLINK3_MK

BUILDLINK_TREE+=	-upower
