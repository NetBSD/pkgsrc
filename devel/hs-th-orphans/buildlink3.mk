# $NetBSD: buildlink3.mk,v 1.2 2025/08/13 11:07:02 pho Exp $

BUILDLINK_TREE+=	hs-th-orphans

.if !defined(HS_TH_ORPHANS_BUILDLINK3_MK)
HS_TH_ORPHANS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-th-orphans+=	hs-th-orphans>=0.13.16
BUILDLINK_ABI_DEPENDS.hs-th-orphans+=	hs-th-orphans>=0.13.16nb1
BUILDLINK_PKGSRCDIR.hs-th-orphans?=	../../devel/hs-th-orphans

.include "../../devel/hs-th-compat/buildlink3.mk"
.include "../../devel/hs-th-lift/buildlink3.mk"
.include "../../devel/hs-th-reify-many/buildlink3.mk"
.endif	# HS_TH_ORPHANS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-th-orphans
