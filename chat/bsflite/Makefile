# $NetBSD: Makefile,v 1.2 2005/02/28 20:58:14 reed Exp $

DISTNAME=	bsflite-0.73
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=bsflite/}

MAINTAINER=	leitec@leitec.org
HOMEPAGE=	http://bsflite.sourceforge.net/
COMMENT=	Lightweight AIM client for the command line

INSTALLATION_DIRS=	bin share/doc/bsflite

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bsflite ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/COPYING ${PREFIX}/share/doc/bsflite
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${PREFIX}/share/doc/bsflite
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/bsflite

.include "../../mk/bsd.pkg.mk"
