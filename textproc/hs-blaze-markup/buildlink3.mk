# $NetBSD: buildlink3.mk,v 1.12 2021/05/03 19:01:12 pho Exp $

BUILDLINK_TREE+=	hs-blaze-markup

.if !defined(HS_BLAZE_MARKUP_BUILDLINK3_MK)
HS_BLAZE_MARKUP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-blaze-markup+=	hs-blaze-markup>=0.8.2
BUILDLINK_ABI_DEPENDS.hs-blaze-markup+=	hs-blaze-markup>=0.8.2.8nb1
BUILDLINK_PKGSRCDIR.hs-blaze-markup?=	../../textproc/hs-blaze-markup

.include "../../devel/hs-blaze-builder/buildlink3.mk"
.endif	# HS_BLAZE_MARKUP_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-blaze-markup
