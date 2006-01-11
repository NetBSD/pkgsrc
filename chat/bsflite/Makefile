# $NetBSD: Makefile,v 1.6 2006/01/11 18:13:25 wiz Exp $

DISTNAME=	bsflite-0.81
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=bsflite/}

MAINTAINER=	leitec@leitec.org
HOMEPAGE=	http://bsflite.sourceforge.net/
COMMENT=	Lightweight AIM client for the command line

INSTALLATION_DIRS=	bin share/doc/bsflite share/examples/bsflite

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bsflite ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/COPYING ${PREFIX}/share/doc/bsflite
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${PREFIX}/share/doc/bsflite
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/bsflite
	${INSTALL_DATA} ${WRKSRC}/config-example \
		${PREFIX}/share/examples/bsflite

LIBS.SunOS+=	-lnsl -lsocket
MAKE_ENV+=	LIBS=${LIBS:M*:Q}

.include "../../mk/bsd.pkg.mk"
