# $NetBSD: Makefile,v 1.129 2020/06/09 11:27:04 nia Exp $

DISTNAME=	harfbuzz-2.6.7
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GITHUB:=harfbuzz/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://harfbuzz.github.io/
COMMENT=	OpenType text shaping engine
LICENSE=	mit

# C++11
GCC_REQD+=	4.9

.include "../../mk/bsd.prefs.mk"
PLIST_VARS+=		graphite2
.include "../../graphics/librsvg/available.mk"

USE_LANGUAGES=		c c++11
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-cairo=no
.if ${LIBRSVG_TYPE} == "rust"
CONFIGURE_ARGS+=	--with-graphite2=yes
PLIST.graphite2=	yes
.else
CONFIGURE_ARGS+=	--with-graphite2=no
.endif

PKGCONFIG_OVERRIDE+=	src/harfbuzz.pc.in
PKGCONFIG_OVERRIDE+=	src/harfbuzz-icu.pc.in
PKGCONFIG_OVERRIDE+=	src/harfbuzz-subset.pc.in

LDFLAGS.OpenBSD+=	-lz

.include "options.mk"

# gcc too old
BUILDLINK_TRANSFORM.MirBSD+=	rm:-fvisibility-inlines-hidden

PLIST_VARS+=	coretext

.if ${OPSYS} == "Darwin"
.  if !empty(OS_VERSION:M[0-8].*)
# MacOS X < 10.5 does not have CoreText.
CONFIGURE_ARGS+=	--with-coretext=no

.  elif !empty(OS_VERSION:M9.*)
# MacOS X 10.5 has CoreText but it's
# buggy. CTLineCreateWithAttributedString() seemingly fails when
# trying to use a font which isn't installed into the system standard
# path.
# See http://forum.libcinder.org/topic/text-not-working-in-leopard-osx-10-5
CONFIGURE_ARGS+=	--with-coretext=no

.  else
CONFIGURE_ARGS+=	--with-coretext=yes
PLIST.coretext=		yes
.  endif
.endif

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
#cairo is only needed for the hb-view command line utility
#BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.8.0
#.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.if ${LIBRSVG_TYPE} == "rust"
# graphite2 support breaks graphics/librsvg-c
.include "../../graphics/graphite2/buildlink3.mk"
.endif
.include "../../mk/bsd.pkg.mk"
