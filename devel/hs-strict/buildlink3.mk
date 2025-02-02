# $NetBSD: buildlink3.mk,v 1.13 2025/02/02 13:05:24 pho Exp $

BUILDLINK_TREE+=	hs-strict

.if !defined(HS_STRICT_BUILDLINK3_MK)
HS_STRICT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-strict+=	hs-strict>=0.5.1
BUILDLINK_ABI_DEPENDS.hs-strict+=	hs-strict>=0.5.1nb1
BUILDLINK_PKGSRCDIR.hs-strict?=		../../devel/hs-strict

.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../devel/hs-these/buildlink3.mk"
.include "../../devel/hs-assoc/buildlink3.mk"
.endif	# HS_STRICT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-strict
