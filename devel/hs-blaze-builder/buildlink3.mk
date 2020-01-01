# $NetBSD: buildlink3.mk,v 1.10 2020/01/01 06:44:06 pho Exp $

BUILDLINK_TREE+=	hs-blaze-builder

.if !defined(HS_BLAZE_BUILDER_BUILDLINK3_MK)
HS_BLAZE_BUILDER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-blaze-builder+=	hs-blaze-builder>=0.4.1
BUILDLINK_ABI_DEPENDS.hs-blaze-builder+=	hs-blaze-builder>=0.4.1.0
BUILDLINK_PKGSRCDIR.hs-blaze-builder?=		../../devel/hs-blaze-builder

.include "../../devel/hs-text/buildlink3.mk"
.include "../../math/hs-semigroups/buildlink3.mk"
.endif	# HS_BLAZE_BUILDER_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-blaze-builder
