# $NetBSD: buildlink3.mk,v 1.4 2023/02/07 01:40:47 pho Exp $

BUILDLINK_TREE+=	hs-primitive-extras

.if !defined(HS_PRIMITIVE_EXTRAS_BUILDLINK3_MK)
HS_PRIMITIVE_EXTRAS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-primitive-extras+=	hs-primitive-extras>=0.10.1
BUILDLINK_ABI_DEPENDS.hs-primitive-extras+=	hs-primitive-extras>=0.10.1.5nb1
BUILDLINK_PKGSRCDIR.hs-primitive-extras?=	../../devel/hs-primitive-extras

.include "../../devel/hs-cereal/buildlink3.mk"
.include "../../devel/hs-deferred-folds/buildlink3.mk"
.include "../../devel/hs-focus/buildlink3.mk"
.include "../../devel/hs-foldl/buildlink3.mk"
.include "../../devel/hs-list-t/buildlink3.mk"
.include "../../devel/hs-primitive/buildlink3.mk"
.include "../../devel/hs-primitive-unlifted/buildlink3.mk"
.include "../../math/hs-profunctors/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.endif	# HS_PRIMITIVE_EXTRAS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-primitive-extras
