# $NetBSD: buildlink3.mk,v 1.8 2025/03/05 03:40:04 pho Exp $

BUILDLINK_TREE+=	hs-text-rope

.if !defined(HS_TEXT_ROPE_BUILDLINK3_MK)
HS_TEXT_ROPE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-text-rope+=	hs-text-rope>=0.3
BUILDLINK_ABI_DEPENDS.hs-text-rope+=	hs-text-rope>=0.3nb2
BUILDLINK_PKGSRCDIR.hs-text-rope?=	../../textproc/hs-text-rope

.include "../../devel/hs-vector/buildlink3.mk"
.endif	# HS_TEXT_ROPE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-text-rope
