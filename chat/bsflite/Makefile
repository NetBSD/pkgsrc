# $NetBSD: Makefile,v 1.13 2012/10/03 00:02:34 asau Exp $

DISTNAME=	bsflite-0.85
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=bsflite/}

MAINTAINER=	bsflite@leitec.org
HOMEPAGE=	http://bsflite.sourceforge.net/
COMMENT=	Lightweight AIM client for the command line
LICENSE=	modified-bsd

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1
INSTALLATION_DIRS+=	share/doc/bsflite share/examples/bsflite

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bsflite ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/bsflite.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DESTDIR}${PREFIX}/share/doc/bsflite
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${DESTDIR}${PREFIX}/share/doc/bsflite
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/bsflite
	${INSTALL_DATA} ${WRKSRC}/config-example \
		${DESTDIR}${PREFIX}/share/examples/bsflite

LIBS.SunOS+=	-lnsl -lsocket
MAKE_ENV+=	LIBS=${LIBS:Q}

.include "../../mk/bsd.pkg.mk"
