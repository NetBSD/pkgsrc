# $NetBSD: buildlink3.mk,v 1.5 2022/02/26 03:58:08 pho Exp $

BUILDLINK_TREE+=	hs-strict

.if !defined(HS_STRICT_BUILDLINK3_MK)
HS_STRICT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-strict+=	hs-strict>=0.4.0
BUILDLINK_ABI_DEPENDS.hs-strict+=	hs-strict>=0.4.0.1nb4
BUILDLINK_PKGSRCDIR.hs-strict?=		../../devel/hs-strict

.include "../../devel/hs-assoc/buildlink3.mk"
.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../devel/hs-these/buildlink3.mk"
.endif	# HS_STRICT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-strict
