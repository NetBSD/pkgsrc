# $NetBSD: buildlink3.mk,v 1.6 2023/11/02 06:36:45 pho Exp $

BUILDLINK_TREE+=	hs-managed

.if !defined(HS_MANAGED_BUILDLINK3_MK)
HS_MANAGED_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-managed+=	hs-managed>=1.0.10
BUILDLINK_ABI_DEPENDS.hs-managed+=	hs-managed>=1.0.10nb1
BUILDLINK_PKGSRCDIR.hs-managed?=	../../devel/hs-managed
.endif	# HS_MANAGED_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-managed
