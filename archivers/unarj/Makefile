# $NetBSD: Makefile,v 1.9 2001/02/16 13:15:37 wiz Exp $

DISTNAME=       unarj-2.43
CATEGORIES=	archivers
MASTER_SITES=	ftp://ftp.kiarchive.ru/pub/unix/arcers/
EXTRACT_SUFX=	.tgz

MAINTAINER=     packages@netbsd.org
HOMEPAGE=	http://www.arjsoftware.com/
COMMENT=	Allows files to be extracted from ARJ archives

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/unarj
	${INSTALL_PROGRAM} ${WRKSRC}/unarj ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/unarj.doc ${PREFIX}/share/doc/unarj
	${INSTALL_MAN} ${WRKSRC}/technote.doc ${PREFIX}/share/doc/unarj

.include "../../mk/bsd.pkg.mk"
