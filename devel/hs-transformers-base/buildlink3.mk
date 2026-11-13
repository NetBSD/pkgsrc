# $NetBSD: buildlink3.mk,v 1.20 2026/11/13 14:39:22 pho Exp $

BUILDLINK_TREE+=	hs-transformers-base

.if !defined(HS_TRANSFORMERS_BASE_BUILDLINK3_MK)
HS_TRANSFORMERS_BASE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-transformers-base+=	hs-transformers-base>=0.4.6
BUILDLINK_ABI_DEPENDS.hs-transformers-base+=	hs-transformers-base>=0.4.6nb10
BUILDLINK_PKGSRCDIR.hs-transformers-base?=	../../devel/hs-transformers-base

.include "../../devel/hs-base-orphans/buildlink3.mk"
.include "../../devel/hs-transformers-compat/buildlink3.mk"
.endif	# HS_TRANSFORMERS_BASE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-transformers-base
