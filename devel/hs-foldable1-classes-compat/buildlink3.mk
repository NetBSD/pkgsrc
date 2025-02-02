# $NetBSD: buildlink3.mk,v 1.5 2025/02/02 13:05:06 pho Exp $

BUILDLINK_TREE+=	hs-foldable1-classes-compat

.if !defined(HS_FOLDABLE1_CLASSES_COMPAT_BUILDLINK3_MK)
HS_FOLDABLE1_CLASSES_COMPAT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-foldable1-classes-compat+=	hs-foldable1-classes-compat>=0.1.1
BUILDLINK_ABI_DEPENDS.hs-foldable1-classes-compat+=	hs-foldable1-classes-compat>=0.1.1nb1
BUILDLINK_PKGSRCDIR.hs-foldable1-classes-compat?=	../../devel/hs-foldable1-classes-compat

.include "../../devel/hs-tagged/buildlink3.mk"
.endif	# HS_FOLDABLE1_CLASSES_COMPAT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-foldable1-classes-compat
