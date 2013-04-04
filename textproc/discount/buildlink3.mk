# $NetBSD: buildlink3.mk,v 1.1 2013/04/04 09:40:23 wiz Exp $

BUILDLINK_TREE+=	discount

.if !defined(DISCOUNT_BUILDLINK3_MK)
DISCOUNT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.discount+=	discount>=2.1.6
BUILDLINK_PKGSRCDIR.discount?=		../../textproc/discount
.endif	# DISCOUNT_BUILDLINK3_MK

BUILDLINK_TREE+=	-discount
