# $NetBSD: Makefile,v 1.8 1999/12/24 00:07:15 wiz Exp $

DISTNAME=       unarj-2.43
CATEGORIES=	archivers
MASTER_SITES=	ftp://ftp.kiarchive.ru/pub/unix/arcers/
EXTRACT_SUFX=	.tgz

MAINTAINER=     packages@netbsd.org
HOMEPAGE=	http://www.arjsoftware.com/

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/unarj
	${INSTALL_PROGRAM} ${WRKSRC}/unarj ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/unarj.doc ${PREFIX}/share/doc/unarj
	${INSTALL_MAN} ${WRKSRC}/technote.doc ${PREFIX}/share/doc/unarj

.include "../../mk/bsd.pkg.mk"
