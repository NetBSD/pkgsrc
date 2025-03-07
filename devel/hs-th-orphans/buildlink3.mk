# $NetBSD: buildlink3.mk,v 1.1 2025/03/07 16:48:18 pho Exp $

BUILDLINK_TREE+=	hs-th-orphans

.if !defined(HS_TH_ORPHANS_BUILDLINK3_MK)
HS_TH_ORPHANS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-th-orphans+=	hs-th-orphans>=0.13.16
BUILDLINK_ABI_DEPENDS.hs-th-orphans+=	hs-th-orphans>=0.13.16
BUILDLINK_PKGSRCDIR.hs-th-orphans?=	../../devel/hs-th-orphans

.include "../../devel/hs-th-compat/buildlink3.mk"
.include "../../devel/hs-th-lift/buildlink3.mk"
.include "../../devel/hs-th-reify-many/buildlink3.mk"
.endif	# HS_TH_ORPHANS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-th-orphans
