# $NetBSD: buildlink3.mk,v 1.8 2025/02/02 13:05:14 pho Exp $

BUILDLINK_TREE+=	hs-managed

.if !defined(HS_MANAGED_BUILDLINK3_MK)
HS_MANAGED_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-managed+=	hs-managed>=1.0.10
BUILDLINK_ABI_DEPENDS.hs-managed+=	hs-managed>=1.0.10nb3
BUILDLINK_PKGSRCDIR.hs-managed?=	../../devel/hs-managed
.endif	# HS_MANAGED_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-managed
