# $NetBSD: buildlink3.mk,v 1.7 2023/02/07 01:40:52 pho Exp $

BUILDLINK_TREE+=	hs-these

.if !defined(HS_THESE_BUILDLINK3_MK)
HS_THESE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-these+=	hs-these>=1.1.1
BUILDLINK_ABI_DEPENDS.hs-these+=	hs-these>=1.1.1.1nb5
BUILDLINK_PKGSRCDIR.hs-these?=		../../devel/hs-these

.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../devel/hs-assoc/buildlink3.mk"
.endif	# HS_THESE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-these
