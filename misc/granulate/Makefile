# $NetBSD: Makefile,v 1.6 2008/03/04 19:21:11 jlam Exp $
#

DISTNAME=	granulate-0.1
CATEGORIES=	misc
MASTER_SITES=	ftp://134.74.16.12/pub/

MAINTAINER=	zuntum@NetBSD.org
COMMENT=	Program for splitting files in place

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/granulate ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/granulate
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/granulate

.include "../../mk/bsd.pkg.mk"
