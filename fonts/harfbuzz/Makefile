# $NetBSD: Makefile,v 1.32 2014/05/04 16:58:45 wiz Exp $

DISTNAME=	harfbuzz-0.9.28
CATEGORIES=	fonts
MASTER_SITES=	http://www.freedesktop.org/software/harfbuzz/release/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://harfbuzz.org/
COMMENT=	OpenType text shaping engine
LICENSE=	mit

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-cairo=no
CONFIGURE_ARGS+=	--with-coretext=auto

PKGCONFIG_OVERRIDE+=	src/harfbuzz.pc.in
PKGCONFIG_OVERRIDE+=	src/harfbuzz-icu.pc.in

LDFLAGS.OpenBSD+=	-lz

.include "options.mk"

.include "../../mk/bsd.prefs.mk"

# gcc too old
.if ${OPSYS} == "MirBSD"
BUILDLINK_TRANSFORM+=	rm:-fvisibility-inlines-hidden
.endif

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
#cairo is only needed for the hb-view command line utility
#BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.8.0
#.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
