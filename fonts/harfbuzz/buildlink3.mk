# $NetBSD: buildlink3.mk,v 1.11 2019/06/08 19:53:26 leot Exp $

BUILDLINK_TREE+=	harfbuzz

.if !defined(HARFBUZZ_BUILDLINK3_MK)
HARFBUZZ_BUILDLINK3_MK:=

.include "../../graphics/librsvg/available.mk"

BUILDLINK_API_DEPENDS.harfbuzz+=	harfbuzz>=2.1.1
BUILDLINK_ABI_DEPENDS.harfbuzz+=	harfbuzz>=2.1.1
BUILDLINK_PKGSRCDIR.harfbuzz?=		../../fonts/harfbuzz

.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.if ${LIBRSVG_TYPE} == "rust"
.include "../../graphics/graphite2/buildlink3.mk"
.endif
.endif	# HARFBUZZ_BUILDLINK3_MK

BUILDLINK_TREE+=	-harfbuzz
