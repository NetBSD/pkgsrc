# $NetBSD: Makefile,v 1.4 2000/03/28 00:09:20 dmcmahill Exp $

DISTNAME=	musicbox-1.01p2
CATEGORIES=	audio
MASTER_SITES=	ftp://freebsd.csie.nctu.edu.tw/Upload/
EXTRACT_SUFX=	.tgz

MAINTAINER=	rxg@ms25.url.com.tw

DEPENDS+=	mpg123-0.59r:../../audio/mpg123
DEPENDS+=	qt1-1.44:../../x11/qt1

USE_X11=	yes

WRKSRC=		${WRKDIR}/musicbox-1.01

PATH=	${X11BASE}/qt1/bin:$$PATH

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/musicbox ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/doc/musicbox
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/musicbox/README

.include "../../mk/bsd.pkg.mk"
