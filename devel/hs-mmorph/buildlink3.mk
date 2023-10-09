# $NetBSD: buildlink3.mk,v 1.15 2023/10/09 04:54:24 pho Exp $

BUILDLINK_TREE+=	hs-mmorph

.if !defined(HS_MMORPH_BUILDLINK3_MK)
HS_MMORPH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-mmorph+=	hs-mmorph>=1.2.0
BUILDLINK_ABI_DEPENDS.hs-mmorph+=	hs-mmorph>=1.2.0nb4
BUILDLINK_PKGSRCDIR.hs-mmorph?=		../../devel/hs-mmorph

.include "../../devel/hs-transformers-compat/buildlink3.mk"
.endif	# HS_MMORPH_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-mmorph
