# $NetBSD: buildlink3.mk,v 1.2 2023/11/02 06:36:54 pho Exp $

BUILDLINK_TREE+=	hs-row-types

.if !defined(HS_ROW_TYPES_BUILDLINK3_MK)
HS_ROW_TYPES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-row-types+=	hs-row-types>=1.0.1
BUILDLINK_ABI_DEPENDS.hs-row-types+=	hs-row-types>=1.0.1.2nb1
BUILDLINK_PKGSRCDIR.hs-row-types?=	../../devel/hs-row-types

.include "../../devel/hs-constraints/buildlink3.mk"
.include "../../devel/hs-generic-lens/buildlink3.mk"
.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../math/hs-profunctors/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.endif	# HS_ROW_TYPES_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-row-types
