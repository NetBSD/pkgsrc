# $NetBSD: Makefile,v 1.3 2001/04/22 21:52:23 zuntum Exp $
#

DISTNAME=	granulate-0.1
CATEGORIES=	misc
MASTER_SITES=	ftp://134.74.16.12/pub/

MAINTAINER=	zuntum@netbsd.org
COMMENT=	Program for splitting files in place

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/granulate ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/granulate
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/granulate

.include "../../mk/bsd.pkg.mk"
