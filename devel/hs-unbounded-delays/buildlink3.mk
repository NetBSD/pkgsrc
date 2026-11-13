# $NetBSD: buildlink3.mk,v 1.14 2026/11/13 14:39:23 pho Exp $

BUILDLINK_TREE+=	hs-unbounded-delays

.if !defined(HS_UNBOUNDED_DELAYS_BUILDLINK3_MK)
HS_UNBOUNDED_DELAYS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-unbounded-delays+=	hs-unbounded-delays>=0.1.1
BUILDLINK_ABI_DEPENDS.hs-unbounded-delays+=	hs-unbounded-delays>=0.1.1.1nb12
BUILDLINK_PKGSRCDIR.hs-unbounded-delays?=	../../devel/hs-unbounded-delays
.endif	# HS_UNBOUNDED_DELAYS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-unbounded-delays
