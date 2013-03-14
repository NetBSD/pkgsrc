# $NetBSD: Makefile,v 1.9 2013/03/14 19:10:29 drochner Exp $

DISTNAME=	harfbuzz-0.9.12
PKGREVISION=	2
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
PKGCONFIG_OVERRIDE=	harfbuzz.pc.in

LDFLAGS.OpenBSD+=	-lz

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
#cairo is only needed for some cmd line utility
#.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
