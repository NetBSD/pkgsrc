# $NetBSD: buildlink3.mk,v 1.9 2018/11/12 03:49:09 ryoon Exp $

BUILDLINK_TREE+=	harfbuzz

.if !defined(HARFBUZZ_BUILDLINK3_MK)
HARFBUZZ_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.harfbuzz+=	harfbuzz>=2.1.1
BUILDLINK_ABI_DEPENDS.harfbuzz+=	harfbuzz>=2.1.1
BUILDLINK_PKGSRCDIR.harfbuzz?=		../../fonts/harfbuzz

.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.endif	# HARFBUZZ_BUILDLINK3_MK

BUILDLINK_TREE+=	-harfbuzz
