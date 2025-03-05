# $NetBSD: buildlink3.mk,v 1.10 2025/03/05 03:39:04 pho Exp $

BUILDLINK_TREE+=	hs-blaze-textual

.if !defined(HS_BLAZE_TEXTUAL_BUILDLINK3_MK)
HS_BLAZE_TEXTUAL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-blaze-textual+=	hs-blaze-textual>=0.2.3
BUILDLINK_ABI_DEPENDS.hs-blaze-textual+=	hs-blaze-textual>=0.2.3.1nb4
BUILDLINK_PKGSRCDIR.hs-blaze-textual?=		../../devel/hs-blaze-textual

.include "../../devel/hs-blaze-builder/buildlink3.mk"
.include "../../devel/hs-old-locale/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.endif	# HS_BLAZE_TEXTUAL_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-blaze-textual
