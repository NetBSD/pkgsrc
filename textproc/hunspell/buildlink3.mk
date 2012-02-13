# $NetBSD: buildlink3.mk,v 1.4 2012/02/13 14:46:11 wiz Exp $

BUILDLINK_TREE+=	hunspell

.if !defined(HUNSPELL_BUILDLINK3_MK)
HUNSPELL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hunspell+=	hunspell>=1.2.2
BUILDLINK_ABI_DEPENDS.hunspell+=	hunspell>=1.3.2
BUILDLINK_PKGSRCDIR.hunspell?=		../../textproc/hunspell
.endif # HUNSPELL_BUILDLINK3_MK

BUILDLINK_TREE+=	-hunspell
