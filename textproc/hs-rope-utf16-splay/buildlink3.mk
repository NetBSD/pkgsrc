# $NetBSD: buildlink3.mk,v 1.4 2023/02/07 01:41:13 pho Exp $

BUILDLINK_TREE+=	hs-rope-utf16-splay

.if !defined(HS_ROPE_UTF16_SPLAY_BUILDLINK3_MK)
HS_ROPE_UTF16_SPLAY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-rope-utf16-splay+=	hs-rope-utf16-splay>=0.4.0
BUILDLINK_ABI_DEPENDS.hs-rope-utf16-splay+=	hs-rope-utf16-splay>=0.4.0.0nb1
BUILDLINK_PKGSRCDIR.hs-rope-utf16-splay?=	../../textproc/hs-rope-utf16-splay
.endif	# HS_ROPE_UTF16_SPLAY_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-rope-utf16-splay
