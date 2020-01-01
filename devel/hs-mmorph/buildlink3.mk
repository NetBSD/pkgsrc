# $NetBSD: buildlink3.mk,v 1.6 2020/01/01 04:35:58 pho Exp $

BUILDLINK_TREE+=	hs-mmorph

.if !defined(HS_MMORPH_BUILDLINK3_MK)
HS_MMORPH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-mmorph+=	hs-mmorph>=1.1.3
BUILDLINK_ABI_DEPENDS.hs-mmorph+=	hs-mmorph>=1.1.3
BUILDLINK_PKGSRCDIR.hs-mmorph?=		../../devel/hs-mmorph

.include "../../devel/hs-mtl/buildlink3.mk"
.include "../../devel/hs-transformers-compat/buildlink3.mk"
.endif	# HS_MMORPH_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-mmorph
