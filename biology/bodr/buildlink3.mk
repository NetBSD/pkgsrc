# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/10/05 22:03:12 ryoon Exp $

BUILDLINK_TREE+=	bodr

.if !defined(BODR_BUILDLINK3_MK)
BODR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.bodr+=	bodr>=8
BUILDLINK_PKGSRCDIR.bodr?=	../../biology/bodr

.endif	# BODR_BUILDLINK3_MK

BUILDLINK_TREE+=	-bodr
