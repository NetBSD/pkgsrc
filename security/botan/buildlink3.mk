# $NetBSD: buildlink3.mk,v 1.6 2009/03/20 19:25:16 joerg Exp $

BUILDLINK_TREE+=	botan

.if !defined(BOTAN_BUILDLINK3_MK)
BOTAN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.botan+=	botan>=1.4.11
BUILDLINK_PKGSRCDIR.botan?=	../../security/botan
.endif # BOTAN_BUILDLINK3_MK

BUILDLINK_TREE+=	-botan
