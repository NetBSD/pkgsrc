# $NetBSD: Makefile,v 1.30 2020/01/26 05:26:14 rillig Exp $
#

DISTNAME=		splay-0.8.2
CATEGORIES=		audio
MASTER_SITES=		# empty

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://splay.sourceforge.net/
COMMENT=		Audio player/decoder that decodes MPEG Layer I,II,III and WAV files
LICENSE=		gnu-gpl-v2

USE_LANGUAGES=		c c++03
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-xsplay
CONFIGURE_ARGS+=	--without-pthread
LIBS+=			${LIBOSSAUDIO}
LIBS.SunOS+=		-lsocket -lnsl

.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
