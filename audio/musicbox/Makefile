# $NetBSD: Makefile,v 1.12 2001/12/03 18:04:34 wiz Exp $

DISTNAME=	musicbox-1.01p2
CATEGORIES=	audio
MASTER_SITES=	ftp://freebsd.csie.nctu.edu.tw/Upload/
EXTRACT_SUFX=	.tgz

MAINTAINER=	rxg@ms25.url.com.tw
COMMENT=	X11 front-interface for mpg123

DEPENDS+=	mpg123>=0.59.18:../../audio/mpg123
DEPENDS+=	qt1-1.44:../../x11/qt1

WRKSRC=		${WRKDIR}/musicbox-1.01

USE_X11=	yes
CFLAGS+=	-D${OPSYS}
EVAL_PREFIX+=	QT1DIR=qt1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/musicbox ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/musicbox
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/musicbox/README

.include "../../mk/bsd.pkg.mk"
