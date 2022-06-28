# $NetBSD: buildlink3.mk,v 1.2 2022/06/28 11:30:59 wiz Exp $

BUILDLINK_TREE+=	bodr

.if !defined(BODR_BUILDLINK3_MK)
BODR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.bodr+=	bodr>=8
BUILDLINK_ABI_DEPENDS.bodr?=	bodr>=9nb17
BUILDLINK_PKGSRCDIR.bodr?=	../../biology/bodr

.endif	# BODR_BUILDLINK3_MK

BUILDLINK_TREE+=	-bodr
