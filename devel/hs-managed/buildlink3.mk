# $NetBSD: buildlink3.mk,v 1.10 2025/08/13 11:06:48 pho Exp $

BUILDLINK_TREE+=	hs-managed

.if !defined(HS_MANAGED_BUILDLINK3_MK)
HS_MANAGED_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-managed+=	hs-managed>=1.0.10
BUILDLINK_ABI_DEPENDS.hs-managed+=	hs-managed>=1.0.10nb5
BUILDLINK_PKGSRCDIR.hs-managed?=	../../devel/hs-managed
.endif	# HS_MANAGED_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-managed
