# $NetBSD: buildlink3.mk,v 1.1 2015/02/21 19:44:55 jmcneill Exp $

BUILDLINK_TREE+=	upower

.if !defined(UPOWER_BUILDLINK3_MK)
UPOWER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.upower+=	upower>=0.99.2
BUILDLINK_PKGSRCDIR.upower?=	../../sysutils/upower

.include "../../devel/glib2/buildlink3.mk"
.endif	# UPOWER_BUILDLINK3_MK

BUILDLINK_TREE+=	-upower
