# $NetBSD: buildlink3.mk,v 1.1 2012/05/30 15:46:00 wiz Exp $

BUILDLINK_TREE+=	libusbx

.if !defined(LIBUSBX_BUILDLINK3_MK)
LIBUSBX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libusbx+=	libusbx>=1.0.11
BUILDLINK_PKGSRCDIR.libusbx?=	../../devel/libusbx
.endif	# LIBUSBX_BUILDLINK3_MK

BUILDLINK_TREE+=	-libusbx
