# $NetBSD: buildlink3.mk,v 1.21 2025/01/25 11:11:19 riastradh Exp $

BUILDLINK_TREE+=	harfbuzz

.if !defined(HARFBUZZ_BUILDLINK3_MK)
HARFBUZZ_BUILDLINK3_MK:=

USE_CXX_FEATURES+=	c++11 is_trivially_copy_constructible

.include "../../graphics/librsvg/available.mk"

BUILDLINK_API_DEPENDS.harfbuzz+=	harfbuzz>=2.1.1
BUILDLINK_ABI_DEPENDS.harfbuzz+=	harfbuzz>=8.4.0
BUILDLINK_PKGSRCDIR.harfbuzz?=		../../fonts/harfbuzz
BUILDLINK_INCDIRS.harfbuzz?=		include/harfbuzz

pkgbase:=	harfbuzz
.include "../../mk/pkg-build-options.mk"

.if ${PKG_BUILD_OPTIONS.harfbuzz:Mintrospection}
.  include "../../devel/glib2/buildlink3.mk"
.endif

.include "../../graphics/freetype2/buildlink3.mk"
.if ${LIBRSVG_TYPE} == "rust"
.include "../../graphics/graphite2/buildlink3.mk"
.endif
.endif	# HARFBUZZ_BUILDLINK3_MK

BUILDLINK_TREE+=	-harfbuzz
