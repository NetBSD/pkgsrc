# $NetBSD: buildlink3.mk,v 1.6 2025/08/15 07:07:11 adam Exp $

BUILDLINK_TREE+=	ldns

.if !defined(LDNS_BUILDLINK3_MK)
LDNS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ldns+=	ldns>=1.4
BUILDLINK_ABI_DEPENDS.ldns+=	ldns>=1.8.4
BUILDLINK_PKGSRCDIR.ldns?=	../../net/ldns
.endif # LDNS_BUILDLINK3_MK

BUILDLINK_TREE+=	-ldns
