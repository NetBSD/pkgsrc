# $NetBSD: Makefile,v 1.3 2001/08/02 17:48:13 drochner Exp $

DISTNAME=	mp3check-0.6.3
CATEGORIES=	audio
#MASTER_SITES=	http://programmierer.freepage.de/cgi-bin/feets/freepage_ext/41030x030A/rewrite/overmann/soft/
MASTER_SITES=	http://overmann.exhome.de/soft/

MAINTAINER=	tron@netbsd.org
#HOMEPAGE=	http://programmierer.freepage.de/overmann/soft/
HOMEPAGE=	http://overmann.exhome.de/soft/soft.html
COMMENT=	Check MP3 files for consistency

#USE_GMAKE=	YES

ALL_TARGET=	mp3check

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mp3check ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/mp3check.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
