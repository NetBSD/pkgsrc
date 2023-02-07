# $NetBSD: buildlink3.mk,v 1.3 2023/02/07 01:40:43 pho Exp $

BUILDLINK_TREE+=	hs-managed

.if !defined(HS_MANAGED_BUILDLINK3_MK)
HS_MANAGED_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-managed+=	hs-managed>=1.0.9
BUILDLINK_ABI_DEPENDS.hs-managed+=	hs-managed>=1.0.9nb2
BUILDLINK_PKGSRCDIR.hs-managed?=	../../devel/hs-managed
.endif	# HS_MANAGED_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-managed
