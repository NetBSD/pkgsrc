# $NetBSD: buildlink3.mk,v 1.2 2022/02/26 03:57:49 pho Exp $

BUILDLINK_TREE+=	hs-blaze-textual

.if !defined(HS_BLAZE_TEXTUAL_BUILDLINK3_MK)
HS_BLAZE_TEXTUAL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-blaze-textual+=	hs-blaze-textual>=0.2.2
BUILDLINK_ABI_DEPENDS.hs-blaze-textual+=	hs-blaze-textual>=0.2.2.1nb1
BUILDLINK_PKGSRCDIR.hs-blaze-textual?=		../../devel/hs-blaze-textual

.include "../../devel/hs-blaze-builder/buildlink3.mk"
.include "../../devel/hs-old-locale/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.endif	# HS_BLAZE_TEXTUAL_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-blaze-textual
