# $NetBSD: buildlink3.mk,v 1.11 2020/01/11 10:48:40 pho Exp $

BUILDLINK_TREE+=	hs-blaze-builder

.if !defined(HS_BLAZE_BUILDER_BUILDLINK3_MK)
HS_BLAZE_BUILDER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-blaze-builder+=	hs-blaze-builder>=0.4.1
BUILDLINK_ABI_DEPENDS.hs-blaze-builder+=	hs-blaze-builder>=0.4.1.0
BUILDLINK_PKGSRCDIR.hs-blaze-builder?=		../../devel/hs-blaze-builder
.endif	# HS_BLAZE_BUILDER_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-blaze-builder
