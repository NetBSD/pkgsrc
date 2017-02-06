# $NetBSD: buildlink3.mk,v 1.7 2017/02/06 12:45:09 wiz Exp $

BUILDLINK_TREE+=	harfbuzz

.if !defined(HARFBUZZ_BUILDLINK3_MK)
HARFBUZZ_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.harfbuzz+=	harfbuzz>=0.9.4
BUILDLINK_ABI_DEPENDS.harfbuzz+=	harfbuzz>=1.4.2
BUILDLINK_PKGSRCDIR.harfbuzz?=		../../fonts/harfbuzz

.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/graphite2/buildlink3.mk"
.endif	# HARFBUZZ_BUILDLINK3_MK

BUILDLINK_TREE+=	-harfbuzz
