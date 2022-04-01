# $NetBSD: buildlink3.mk,v 1.1 2022/04/01 08:00:34 wiz Exp $

BUILDLINK_TREE+=	botan

.if !defined(BOTAN_BUILDLINK3_MK)
BOTAN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.botan+=	botan>=1.10.12<1.11
BUILDLINK_PKGSRCDIR.botan?=	../../security/botan
.endif # BOTAN_BUILDLINK3_MK

BUILDLINK_TREE+=	-botan
