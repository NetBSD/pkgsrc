# $NetBSD: buildlink3.mk,v 1.10 2016/05/19 22:10:24 joerg Exp $

BUILDLINK_TREE+=	botan

.if !defined(BOTAN_BUILDLINK3_MK)
BOTAN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.botan+=	botan>=1.10.12<1.11
BUILDLINK_PKGSRCDIR.botan?=	../../security/botan
.endif # BOTAN_BUILDLINK3_MK

BUILDLINK_TREE+=	-botan
