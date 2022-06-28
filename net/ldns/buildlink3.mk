# $NetBSD: buildlink3.mk,v 1.5 2022/06/28 11:35:01 wiz Exp $

BUILDLINK_TREE+=	ldns

.if !defined(LDNS_BUILDLINK3_MK)
LDNS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ldns+=	ldns>=1.4
BUILDLINK_ABI_DEPENDS.ldns?=	ldns>=1.8.0nb1
BUILDLINK_PKGSRCDIR.ldns?=	../../net/ldns
.endif # LDNS_BUILDLINK3_MK

BUILDLINK_TREE+=	-ldns
