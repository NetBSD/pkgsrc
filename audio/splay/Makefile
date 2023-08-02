# $NetBSD: Makefile,v 1.31 2023/08/02 19:20:17 nia Exp $
#

DISTNAME=		splay-0.8.2
CATEGORIES=		audio
MASTER_SITES=		# empty

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://splay.sourceforge.net/
COMMENT=		Audio player/decoder that decodes MPEG Layer I,II,III and WAV files
LICENSE=		gnu-gpl-v2

USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-xsplay
CONFIGURE_ARGS+=	--without-pthread
LIBS+=			${LIBOSSAUDIO}
LIBS.SunOS+=		-lsocket -lnsl

# Fails with C++14 default language.
FORCE_CXX_STD=	c++03

.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
