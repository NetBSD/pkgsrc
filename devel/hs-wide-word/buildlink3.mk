# $NetBSD: buildlink3.mk,v 1.1 2025/03/07 17:00:46 pho Exp $

BUILDLINK_TREE+=	hs-wide-word

.if !defined(HS_WIDE_WORD_BUILDLINK3_MK)
HS_WIDE_WORD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-wide-word+=	hs-wide-word>=0.1.7
BUILDLINK_ABI_DEPENDS.hs-wide-word+=	hs-wide-word>=0.1.7.0
BUILDLINK_PKGSRCDIR.hs-wide-word?=	../../devel/hs-wide-word

.include "../../devel/hs-primitive/buildlink3.mk"
.include "../../devel/hs-hashable/buildlink3.mk"
.endif	# HS_WIDE_WORD_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-wide-word
