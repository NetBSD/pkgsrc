# $NetBSD: Makefile,v 1.4 2003/02/16 23:08:24 abs Exp $

DISTNAME=	mp3check-0.8.0
CATEGORIES=	audio
MASTER_SITES=	http://www.0vermann.de/soft/mp3check/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.0vermann.de/soft/mp3check/mp3check.html
COMMENT=	Check MP3 files for consistency

#USE_GMAKE=	YES
GNU_CONFIGURE=	YES

ALL_TARGET=	mp3check

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mp3check ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/mp3check.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
