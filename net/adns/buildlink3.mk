# $NetBSD: buildlink3.mk,v 1.9 2015/01/29 09:53:29 mef Exp $

BUILDLINK_TREE+=	adns

.if !defined(ADNS_BUILDLINK3_MK)
ADNS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.adns+=	adns>=1.0
BUILDLINK_ABI_DEPENDS.adns+=	adns>=1.5.0
BUILDLINK_PKGSRCDIR.adns?=	../../net/adns
.endif # ADNS_BUILDLINK3_MK

BUILDLINK_TREE+=	-adns
