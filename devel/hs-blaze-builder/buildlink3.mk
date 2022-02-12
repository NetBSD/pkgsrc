# $NetBSD: buildlink3.mk,v 1.16 2022/02/12 08:50:29 pho Exp $

BUILDLINK_TREE+=	hs-blaze-builder

.if !defined(HS_BLAZE_BUILDER_BUILDLINK3_MK)
HS_BLAZE_BUILDER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-blaze-builder+=	hs-blaze-builder>=0.4.2
BUILDLINK_ABI_DEPENDS.hs-blaze-builder+=	hs-blaze-builder>=0.4.2.2nb1
BUILDLINK_PKGSRCDIR.hs-blaze-builder?=		../../devel/hs-blaze-builder
.endif	# HS_BLAZE_BUILDER_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-blaze-builder
