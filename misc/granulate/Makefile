# $NetBSD: Makefile,v 1.5 2005/06/17 03:50:21 jlam Exp $
#

DISTNAME=	granulate-0.1
CATEGORIES=	misc
MASTER_SITES=	ftp://134.74.16.12/pub/

MAINTAINER=	zuntum@NetBSD.org
COMMENT=	Program for splitting files in place

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/granulate ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/granulate
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/granulate

.include "../../mk/bsd.pkg.mk"
