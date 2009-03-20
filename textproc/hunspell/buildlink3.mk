# $NetBSD: buildlink3.mk,v 1.3 2009/03/20 19:25:29 joerg Exp $

BUILDLINK_TREE+=	hunspell

.if !defined(HUNSPELL_BUILDLINK3_MK)
HUNSPELL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hunspell+=	hunspell>=1.2.2
BUILDLINK_PKGSRCDIR.hunspell?=		../../textproc/hunspell
.endif # HUNSPELL_BUILDLINK3_MK

BUILDLINK_TREE+=	-hunspell
