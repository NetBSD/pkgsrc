# $NetBSD: Makefile,v 1.136 2020/11/05 09:08:06 ryoon Exp $

DISTNAME=	harfbuzz-2.7.2
PKGREVISION=	1
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GITHUB:=harfbuzz/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://harfbuzz.github.io/
COMMENT=	OpenType text shaping engine
LICENSE=	mit

# C++11
GCC_REQD+=	4.9

.include "../../mk/bsd.prefs.mk"
.include "../../graphics/librsvg/available.mk"

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

# cairo/fontconfig are only needed for command line utilities
MESON_ARGS+=	-Dcairo=disabled
MESON_ARGS+=	-Dfontconfig=disabled

MESON_ARGS+=	-Dintrospection=disabled
MESON_ARGS+=	-Dbenchmark=disabled

PLIST_VARS+=		graphite2
.if ${LIBRSVG_TYPE} == "rust"
MESON_ARGS+=		-Dgraphite=enabled
PLIST.graphite2=	yes
.else
MESON_ARGS+=		-Dgraphite=disabled
.endif

PKGCONFIG_OVERRIDE+=	output/meson-private/*.pc

PKGCONFIG_OVERRIDE_STAGE=	pre-install

LDFLAGS.OpenBSD+=	-lz

.include "options.mk"

# gcc too old
BUILDLINK_TRANSFORM.MirBSD+=	rm:-fvisibility-inlines-hidden

PLIST_VARS+=	coretext

.if ${OPSYS} == "Darwin"
.  if !empty(OS_VERSION:M[0-8].*)
# MacOS X < 10.5 does not have CoreText.
MESON_ARGS+=		-Dcoretext=disabled

.  elif !empty(OS_VERSION:M9.*)
# MacOS X 10.5 has CoreText but it's
# buggy. CTLineCreateWithAttributedString() seemingly fails when
# trying to use a font which isn't installed into the system standard
# path.
# See http://forum.libcinder.org/topic/text-not-working-in-leopard-osx-10-5
MESON_ARGS+=		-Dcoretext=disabled

.  else
MESON_ARGS+=		-Dcoretext=enabled
PLIST.coretext=		yes
.  endif
.endif

PYTHON_FOR_BUILD_ONLY=	tool
REPLACE_PYTHON+=	src/*.py

.include "../../devel/meson/build.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
#BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.8.0
#.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.if ${LIBRSVG_TYPE} == "rust"
# graphite2 support breaks graphics/librsvg-c
.include "../../graphics/graphite2/buildlink3.mk"
.endif
.include "../../mk/bsd.pkg.mk"
