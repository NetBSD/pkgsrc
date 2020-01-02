# $NetBSD: buildlink3.mk,v 1.18 2020/01/02 14:41:22 pho Exp $

BUILDLINK_TREE+=	hs-pandoc-types

.if !defined(HS_PANDOC_TYPES_BUILDLINK3_MK)
HS_PANDOC_TYPES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-pandoc-types+=	hs-pandoc-types>=1.17.6
BUILDLINK_ABI_DEPENDS.hs-pandoc-types+=	hs-pandoc-types>=1.17.6.1
BUILDLINK_PKGSRCDIR.hs-pandoc-types?=	../../textproc/hs-pandoc-types

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../devel/hs-QuickCheck/buildlink3.mk"
.include "../../devel/hs-syb/buildlink3.mk"
.include "../../math/hs-semigroups/buildlink3.mk"
.endif	# HS_PANDOC_TYPES_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-pandoc-types
