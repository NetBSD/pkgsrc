# $NetBSD: Makefile,v 1.9 2001/02/16 13:30:48 wiz Exp $

DISTNAME=	musicbox-1.01p2
CATEGORIES=	audio
MASTER_SITES=	ftp://freebsd.csie.nctu.edu.tw/Upload/
EXTRACT_SUFX=	.tgz

MAINTAINER=	rxg@ms25.url.com.tw
COMMENT=	X11 front-interface for mpg123

DEPENDS+=	mpg123-0.59r:../../audio/mpg123
DEPENDS+=	qt1-1.44:../../x11/qt1

USE_X11=	yes

WRKSRC=		${WRKDIR}/musicbox-1.01

EVAL_PREFIX+=	QT1DIR=qt1
PATH=		${QT1DIR}/qt1/bin:$$PATH

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/musicbox ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/doc/musicbox
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/musicbox/README

.include "../../mk/bsd.pkg.mk"
