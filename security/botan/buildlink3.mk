# $NetBSD: buildlink3.mk,v 1.7 2009/09/23 16:03:25 jmmv Exp $

BUILDLINK_TREE+=	botan

.if !defined(BOTAN_BUILDLINK3_MK)
BOTAN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.botan+=	botan>=1.8.7
BUILDLINK_PKGSRCDIR.botan?=	../../security/botan
.endif # BOTAN_BUILDLINK3_MK

BUILDLINK_TREE+=	-botan
