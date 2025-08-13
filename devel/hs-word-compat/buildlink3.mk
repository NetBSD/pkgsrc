# $NetBSD: buildlink3.mk,v 1.2 2025/08/13 11:07:07 pho Exp $

BUILDLINK_TREE+=	hs-word-compat

.if !defined(HS_WORD_COMPAT_BUILDLINK3_MK)
HS_WORD_COMPAT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-word-compat+=	hs-word-compat>=0.0.6
BUILDLINK_ABI_DEPENDS.hs-word-compat+=	hs-word-compat>=0.0.6nb1
BUILDLINK_PKGSRCDIR.hs-word-compat?=	../../devel/hs-word-compat

.endif	# HS_WORD_COMPAT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-word-compat
