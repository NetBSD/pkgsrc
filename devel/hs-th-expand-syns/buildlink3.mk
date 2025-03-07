# $NetBSD: buildlink3.mk,v 1.1 2025/03/07 16:39:41 pho Exp $

BUILDLINK_TREE+=	hs-th-expand-syns

.if !defined(HS_TH_EXPAND_SYNS_BUILDLINK3_MK)
HS_TH_EXPAND_SYNS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-th-expand-syns+=	hs-th-expand-syns>=0.4.12
BUILDLINK_ABI_DEPENDS.hs-th-expand-syns+=	hs-th-expand-syns>=0.4.12.0
BUILDLINK_PKGSRCDIR.hs-th-expand-syns?=		../../devel/hs-th-expand-syns

.include "../../devel/hs-syb/buildlink3.mk"
.include "../../devel/hs-th-abstraction/buildlink3.mk"
.endif	# HS_TH_EXPAND_SYNS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-th-expand-syns
