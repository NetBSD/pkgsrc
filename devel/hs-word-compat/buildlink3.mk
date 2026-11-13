# $NetBSD: buildlink3.mk,v 1.3 2026/11/13 14:39:27 pho Exp $

BUILDLINK_TREE+=	hs-word-compat

.if !defined(HS_WORD_COMPAT_BUILDLINK3_MK)
HS_WORD_COMPAT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-word-compat+=	hs-word-compat>=0.0.6
BUILDLINK_ABI_DEPENDS.hs-word-compat+=	hs-word-compat>=0.0.6nb2
BUILDLINK_PKGSRCDIR.hs-word-compat?=	../../devel/hs-word-compat

.endif	# HS_WORD_COMPAT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-word-compat
