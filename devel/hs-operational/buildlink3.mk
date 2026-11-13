# $NetBSD: buildlink3.mk,v 1.3 2026/11/13 14:39:10 pho Exp $

BUILDLINK_TREE+=	hs-operational

.if !defined(HS_OPERATIONAL_BUILDLINK3_MK)
HS_OPERATIONAL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-operational+=	hs-operational>=0.2.4
BUILDLINK_ABI_DEPENDS.hs-operational+=	hs-operational>=0.2.4.2nb2
BUILDLINK_PKGSRCDIR.hs-operational?=	../../devel/hs-operational

.endif	# HS_OPERATIONAL_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-operational
