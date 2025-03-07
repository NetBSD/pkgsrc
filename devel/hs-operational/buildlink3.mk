# $NetBSD: buildlink3.mk,v 1.1 2025/03/07 12:14:26 pho Exp $

BUILDLINK_TREE+=	hs-operational

.if !defined(HS_OPERATIONAL_BUILDLINK3_MK)
HS_OPERATIONAL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-operational+=	hs-operational>=0.2.4
BUILDLINK_ABI_DEPENDS.hs-operational+=	hs-operational>=0.2.4.2
BUILDLINK_PKGSRCDIR.hs-operational?=	../../devel/hs-operational

.endif	# HS_OPERATIONAL_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-operational
