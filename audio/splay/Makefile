# $NetBSD: Makefile,v 1.25 2012/10/02 23:48:10 asau Exp $
#

DISTNAME=		splay-0.8.2
CATEGORIES=		audio
MASTER_SITES=		# empty

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://splay.sourceforge.net/
COMMENT=		Audio player/decoder that decodes MPEG Layer I,II,III and WAV files

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-xsplay
CONFIGURE_ARGS+=	--without-pthread
LIBS+=			${LIBOSSAUDIO}
LIBS.SunOS+=		-lsocket -lnsl

.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
