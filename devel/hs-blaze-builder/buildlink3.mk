# $NetBSD: buildlink3.mk,v 1.14 2022/01/18 02:48:05 pho Exp $

BUILDLINK_TREE+=	hs-blaze-builder

.if !defined(HS_BLAZE_BUILDER_BUILDLINK3_MK)
HS_BLAZE_BUILDER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-blaze-builder+=	hs-blaze-builder>=0.4.2
BUILDLINK_ABI_DEPENDS.hs-blaze-builder+=	hs-blaze-builder>=0.4.2.1nb2
BUILDLINK_PKGSRCDIR.hs-blaze-builder?=		../../devel/hs-blaze-builder
.endif	# HS_BLAZE_BUILDER_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-blaze-builder
