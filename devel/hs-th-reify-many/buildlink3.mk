# $NetBSD: buildlink3.mk,v 1.2 2025/08/13 11:07:02 pho Exp $

BUILDLINK_TREE+=	hs-th-reify-many

.if !defined(HS_TH_REIFY_MANY_BUILDLINK3_MK)
HS_TH_REIFY_MANY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-th-reify-many+=	hs-th-reify-many>=0.1.10
BUILDLINK_ABI_DEPENDS.hs-th-reify-many+=	hs-th-reify-many>=0.1.10nb1
BUILDLINK_PKGSRCDIR.hs-th-reify-many?=		../../devel/hs-th-reify-many

.include "../../devel/hs-safe/buildlink3.mk"
.include "../../devel/hs-th-expand-syns/buildlink3.mk"
.endif	# HS_TH_REIFY_MANY_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-th-reify-many
