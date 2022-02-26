# $NetBSD: buildlink3.mk,v 1.2 2022/02/26 03:58:30 pho Exp $

BUILDLINK_TREE+=	hs-rope-utf16-splay

.if !defined(HS_ROPE_UTF16_SPLAY_BUILDLINK3_MK)
HS_ROPE_UTF16_SPLAY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-rope-utf16-splay+=	hs-rope-utf16-splay>=0.3.2
BUILDLINK_ABI_DEPENDS.hs-rope-utf16-splay+=	hs-rope-utf16-splay>=0.3.2.0nb1
BUILDLINK_PKGSRCDIR.hs-rope-utf16-splay?=	../../textproc/hs-rope-utf16-splay
.endif	# HS_ROPE_UTF16_SPLAY_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-rope-utf16-splay
