# $NetBSD: buildlink3.mk,v 1.52 2023/02/09 19:49:45 wiz Exp $

BUILDLINK_TREE+=	freetype2

.if !defined(FREETYPE2_BUILDLINK3_MK)
FREETYPE2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.freetype2+=	freetype2>=2.8.1
BUILDLINK_PKGSRCDIR.freetype2?=		../../graphics/freetype2
BUILDLINK_INCDIRS.freetype2?=		include/freetype2

BUILDLINK_FILES.freetype2+=	bin/freetype-config

FREETYPE_CONFIG?=	${BUILDLINK_PREFIX.freetype2}/bin/freetype-config
CONFIGURE_ENV+=		FREETYPE_CONFIG=${FREETYPE_CONFIG:Q}

.include "../../archivers/brotli/buildlink3.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

pkgbase := freetype2
.include "../../mk/pkg-build-options.mk"

.if ${PKG_BUILD_OPTIONS.freetype2:Mpng}
CHECK_BUILTIN.freetype2:=	yes
.include "../../graphics/freetype2/builtin.mk"
CHECK_BUILTIN.freetype2:=	no

.  if ${USE_BUILTIN.freetype2:tl} != yes
.    include "../../graphics/png/buildlink3.mk"
.  endif
.endif

.endif # FREETYPE2_BUILDLINK3_MK

BUILDLINK_TREE+=	-freetype2
