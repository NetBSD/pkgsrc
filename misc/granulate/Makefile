# $NetBSD: Makefile,v 1.4 2003/07/17 21:49:08 grant Exp $
#

DISTNAME=	granulate-0.1
CATEGORIES=	misc
MASTER_SITES=	ftp://134.74.16.12/pub/

MAINTAINER=	zuntum@NetBSD.org
COMMENT=	Program for splitting files in place

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/granulate ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/granulate
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/granulate

.include "../../mk/bsd.pkg.mk"
