# $NetBSD: buildlink3.mk,v 1.4 2009/03/20 19:25:09 joerg Exp $

BUILDLINK_TREE+=	ldns

.if !defined(LDNS_BUILDLINK3_MK)
LDNS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ldns+=	ldns>=1.4
BUILDLINK_PKGSRCDIR.ldns?=	../../net/ldns
.endif # LDNS_BUILDLINK3_MK

BUILDLINK_TREE+=	-ldns
