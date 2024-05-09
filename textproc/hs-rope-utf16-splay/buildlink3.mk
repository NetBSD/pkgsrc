# $NetBSD: buildlink3.mk,v 1.7 2024/05/09 01:32:46 pho Exp $

BUILDLINK_TREE+=	hs-rope-utf16-splay

.if !defined(HS_ROPE_UTF16_SPLAY_BUILDLINK3_MK)
HS_ROPE_UTF16_SPLAY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-rope-utf16-splay+=	hs-rope-utf16-splay>=0.4.0
BUILDLINK_ABI_DEPENDS.hs-rope-utf16-splay+=	hs-rope-utf16-splay>=0.4.0.0nb4
BUILDLINK_PKGSRCDIR.hs-rope-utf16-splay?=	../../textproc/hs-rope-utf16-splay
.endif	# HS_ROPE_UTF16_SPLAY_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-rope-utf16-splay
