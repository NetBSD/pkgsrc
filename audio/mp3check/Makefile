# $NetBSD: Makefile,v 1.6 2004/01/22 07:15:00 grant Exp $

DISTNAME=	mp3check-0.8.0
CATEGORIES=	audio
MASTER_SITES=	http://www.0vermann.de/soft/mp3check/

MAINTAINER=	tron@NetBSD.org
HOMEPAGE=	http://www.0vermann.de/soft/mp3check/mp3check.html
COMMENT=	Check MP3 files for consistency

#USE_GNU_TOOLS+=	make
GNU_CONFIGURE=	YES

ALL_TARGET=	mp3check

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mp3check ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/mp3check.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
