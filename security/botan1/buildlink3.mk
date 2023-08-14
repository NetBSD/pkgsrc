# $NetBSD: buildlink3.mk,v 1.3 2023/08/14 05:25:08 wiz Exp $

BUILDLINK_TREE+=	botan

.if !defined(BOTAN_BUILDLINK3_MK)
BOTAN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.botan+=	botan>=1.10.12<1.11
BUILDLINK_ABI_DEPENDS.botan?=	botan>=1.10.17nb2
BUILDLINK_PKGSRCDIR.botan?=	../../security/botan1
.endif # BOTAN_BUILDLINK3_MK

BUILDLINK_TREE+=	-botan
