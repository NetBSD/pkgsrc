# $NetBSD: buildlink3.mk,v 1.6 2023/01/26 11:28:33 pho Exp $

BUILDLINK_TREE+=	hs-these

.if !defined(HS_THESE_BUILDLINK3_MK)
HS_THESE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-these+=	hs-these>=1.1.1
BUILDLINK_ABI_DEPENDS.hs-these+=	hs-these>=1.1.1.1nb4
BUILDLINK_PKGSRCDIR.hs-these?=		../../devel/hs-these

.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../devel/hs-assoc/buildlink3.mk"
.endif	# HS_THESE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-these
