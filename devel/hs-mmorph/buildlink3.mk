# $NetBSD: buildlink3.mk,v 1.9 2021/05/03 19:01:00 pho Exp $

BUILDLINK_TREE+=	hs-mmorph

.if !defined(HS_MMORPH_BUILDLINK3_MK)
HS_MMORPH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-mmorph+=	hs-mmorph>=1.1.5
BUILDLINK_ABI_DEPENDS.hs-mmorph+=	hs-mmorph>=1.1.5nb1
BUILDLINK_PKGSRCDIR.hs-mmorph?=		../../devel/hs-mmorph

.include "../../devel/hs-transformers-compat/buildlink3.mk"
.endif	# HS_MMORPH_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-mmorph
