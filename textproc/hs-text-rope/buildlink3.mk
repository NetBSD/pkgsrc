# $NetBSD: buildlink3.mk,v 1.2 2023/02/07 01:41:14 pho Exp $

BUILDLINK_TREE+=	hs-text-rope

.if !defined(HS_TEXT_ROPE_BUILDLINK3_MK)
HS_TEXT_ROPE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-text-rope+=	hs-text-rope>=0.2
BUILDLINK_ABI_DEPENDS.hs-text-rope+=	hs-text-rope>=0.2nb1
BUILDLINK_PKGSRCDIR.hs-text-rope?=	../../textproc/hs-text-rope

.include "../../devel/hs-vector/buildlink3.mk"
.endif	# HS_TEXT_ROPE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-text-rope
