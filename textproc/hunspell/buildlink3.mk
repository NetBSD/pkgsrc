# $NetBSD: buildlink3.mk,v 1.8 2022/08/14 20:44:00 tnn Exp $

BUILDLINK_TREE+=	hunspell

.if !defined(HUNSPELL_BUILDLINK3_MK)
HUNSPELL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hunspell+=	hunspell>=1.2.2
BUILDLINK_ABI_DEPENDS.hunspell+=	hunspell>=1.7.0nb7
BUILDLINK_PKGSRCDIR.hunspell?=		../../textproc/hunspell

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.endif # HUNSPELL_BUILDLINK3_MK

BUILDLINK_TREE+=	-hunspell
