# $NetBSD: Makefile,v 1.1.1.1 2000/10/15 21:57:46 tron Exp $

DISTNAME=	mp3check-0.5.2
CATEGORIES=	audio
MASTER_SITES=	http://programmierer.freepage.de/cgi-bin/feets/freepage_ext/41030x030A/rewrite/overmann/soft/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://programmierer.freepage.de/overmann/soft/

USE_GMAKE=	YES

ALL_TARGET=	mp3check

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mp3check ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
