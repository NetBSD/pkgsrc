# $NetBSD: Makefile,v 1.16 2004/05/03 23:45:18 minskim Exp $
#

DISTNAME=		splay-0.8.2
CATEGORIES=		audio
MASTER_SITES=		# empty

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://splay.sourceforge.net/
COMMENT=		Audio player/decoder that decodes MPEG Layer I,II,III and WAV files

USE_BUILDLINK3=		yes
USE_LANGUAGES=		c++
GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--without-xsplay --without-pthread
LIBS+=			${LIBOSSAUDIO}

.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
