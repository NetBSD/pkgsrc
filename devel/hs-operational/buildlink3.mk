# $NetBSD: buildlink3.mk,v 1.2 2025/08/13 11:06:51 pho Exp $

BUILDLINK_TREE+=	hs-operational

.if !defined(HS_OPERATIONAL_BUILDLINK3_MK)
HS_OPERATIONAL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-operational+=	hs-operational>=0.2.4
BUILDLINK_ABI_DEPENDS.hs-operational+=	hs-operational>=0.2.4.2nb1
BUILDLINK_PKGSRCDIR.hs-operational?=	../../devel/hs-operational

.endif	# HS_OPERATIONAL_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-operational
