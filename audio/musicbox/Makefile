# $NetBSD: Makefile,v 1.5 2000/07/10 15:08:14 agc Exp $

DISTNAME=	musicbox-1.01p2
CATEGORIES=	audio
MASTER_SITES=	ftp://freebsd.csie.nctu.edu.tw/Upload/
EXTRACT_SUFX=	.tgz

MAINTAINER=	rxg@ms25.url.com.tw

DEPENDS+=	mpg123-0.59r:../../audio/mpg123
DEPENDS+=	qt1-1.44:../../x11/qt1

USE_X11=	yes

WRKSRC=		${WRKDIR}/musicbox-1.01

PATH=	`${PKG_INFO} -qp qt1 | ${AWK} '{ print $$2 }'`/qt1/bin:$$PATH

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/musicbox ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/doc/musicbox
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/musicbox/README

.include "../../mk/bsd.pkg.mk"
