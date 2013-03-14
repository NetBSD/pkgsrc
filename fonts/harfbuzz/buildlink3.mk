# $NetBSD: buildlink3.mk,v 1.3 2013/03/14 19:10:29 drochner Exp $

BUILDLINK_TREE+=	harfbuzz

.if !defined(HARFBUZZ_BUILDLINK3_MK)
HARFBUZZ_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.harfbuzz+=	harfbuzz>=0.9.4
BUILDLINK_ABI_DEPENDS.harfbuzz?=		harfbuzz>=0.9.12nb1
BUILDLINK_PKGSRCDIR.harfbuzz?=		../../fonts/harfbuzz

.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.endif	# HARFBUZZ_BUILDLINK3_MK

BUILDLINK_TREE+=	-harfbuzz
