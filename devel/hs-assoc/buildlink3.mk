# $NetBSD: buildlink3.mk,v 1.6 2023/02/07 01:40:27 pho Exp $

BUILDLINK_TREE+=	hs-assoc

.if !defined(HS_ASSOC_BUILDLINK3_MK)
HS_ASSOC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-assoc+=	hs-assoc>=1.0.2
BUILDLINK_ABI_DEPENDS.hs-assoc+=	hs-assoc>=1.0.2nb5
BUILDLINK_PKGSRCDIR.hs-assoc?=		../../devel/hs-assoc

.include "../../math/hs-bifunctors/buildlink3.mk"
.include "../../devel/hs-tagged/buildlink3.mk"
.endif	# HS_ASSOC_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-assoc
