# $NetBSD: buildlink3.mk,v 1.7 2020/01/11 08:20:36 pho Exp $

BUILDLINK_TREE+=	hs-mmorph

.if !defined(HS_MMORPH_BUILDLINK3_MK)
HS_MMORPH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-mmorph+=	hs-mmorph>=1.1.3
BUILDLINK_ABI_DEPENDS.hs-mmorph+=	hs-mmorph>=1.1.3
BUILDLINK_PKGSRCDIR.hs-mmorph?=		../../devel/hs-mmorph

.include "../../devel/hs-transformers-compat/buildlink3.mk"
.endif	# HS_MMORPH_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-mmorph
