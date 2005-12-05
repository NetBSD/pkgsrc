# $NetBSD: Makefile,v 1.19 2005/12/05 20:49:49 rillig Exp $
#

DISTNAME=		splay-0.8.2
CATEGORIES=		audio
MASTER_SITES=		# empty

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://splay.sourceforge.net/
COMMENT=		Audio player/decoder that decodes MPEG Layer I,II,III and WAV files

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		c++
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-xsplay
CONFIGURE_ARGS+=	--without-pthread
LIBS+=			${LIBOSSAUDIO}

.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
