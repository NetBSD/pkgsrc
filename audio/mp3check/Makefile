# $NetBSD: Makefile,v 1.9 2005/02/16 12:20:35 wiz Exp $

DISTNAME=	mp3check-0.8.0
CATEGORIES=	audio
MASTER_SITES=	http://jo.ath.cx/soft/mp3check/

MAINTAINER=	tron@NetBSD.org
HOMEPAGE=	http://jo.ath.cx/soft/mp3check/mp3check.html
COMMENT=	Check MP3 files for consistency

#USE_GNU_TOOLS+=	make
GNU_CONFIGURE=	YES
USE_LANGUAGES=	c c++

BUILD_TARGET=	mp3check

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mp3check ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/mp3check.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
