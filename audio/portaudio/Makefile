# $NetBSD: Makefile,v 1.2 2004/10/05 03:53:15 ben Exp $
#

DISTNAME=		portaudio_v18_1
PKGNAME=		portaudio-18.1
PKGREVISION=		1
CATEGORIES=		audio
MASTER_SITES=		http://www.portaudio.com/archives/
EXTRACT_SUFX=		.zip

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://www.portaudio.com/archives/
COMMENT=		Portable cross-platform Audio API

HAS_CONFIGURE=		YES
USE_GNU_TOOLS+=		make
USE_BUILDLINK3=		YES
USE_LIBTOOL=		YES

CONFIGURE_ARGS=		--prefix=${PREFIX}
EXTRACT_CMD_OPTS.zip=	-aqo

pre-configure:
	${CHMOD} 755 ${WRKSRC}/configure

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
