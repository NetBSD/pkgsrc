# $NetBSD: Makefile,v 1.64 2016/03/03 12:34:33 wiz Exp $

DISTNAME=	harfbuzz-1.2.3
CATEGORIES=	fonts
MASTER_SITES=	http://www.freedesktop.org/software/harfbuzz/release/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://harfbuzz.org/
COMMENT=	OpenType text shaping engine
LICENSE=	mit

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-cairo=no

PKGCONFIG_OVERRIDE+=	src/harfbuzz.pc.in
PKGCONFIG_OVERRIDE+=	src/harfbuzz-icu.pc.in

LDFLAGS.OpenBSD+=	-lz

.include "options.mk"

.include "../../mk/bsd.prefs.mk"

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
.include "../../mk/bsd.pkg.mk"
