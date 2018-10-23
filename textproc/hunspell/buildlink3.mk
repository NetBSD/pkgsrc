# $NetBSD: buildlink3.mk,v 1.5 2018/10/23 11:45:34 bsiegert Exp $

BUILDLINK_TREE+=	hunspell

.if !defined(HUNSPELL_BUILDLINK3_MK)
HUNSPELL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hunspell+=	hunspell>=1.2.2
BUILDLINK_ABI_DEPENDS.hunspell+=	hunspell>=1.6.2
BUILDLINK_PKGSRCDIR.hunspell?=		../../textproc/hunspell
.endif # HUNSPELL_BUILDLINK3_MK

BUILDLINK_TREE+=	-hunspell
