# $NetBSD: Makefile,v 1.2 1999/07/10 10:40:37 tron Exp $

DISTNAME=	musicbox-1.01p2
CATEGORIES=	audio
MASTER_SITES=	ftp://freebsd.csie.nctu.edu.tw/Upload/
EXTRACT_SUFX=	.tgz

MAINTAINER=	rxg@ms25.url.com.tw

DEPENDS+=	mpg123-0.59r:../../audio/mpg123
DEPENDS+=	qt-1.44:../../x11/qt

USE_X11=	yes

WRKSRC=		${WRKDIR}/musicbox-1.01

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/musicbox ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/doc/musicbox
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/musicbox/README

.include "../../mk/bsd.pkg.mk"
