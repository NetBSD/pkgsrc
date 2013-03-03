# $NetBSD: Makefile,v 1.9 2013/03/03 11:03:29 shattered Exp $
#

DISTNAME=	granulate-0.2
CATEGORIES=	misc
MASTER_SITES=	ftp://134.74.16.12/pub/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Program for splitting files in place

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/granulate ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/granulate
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/granulate

.include "../../mk/bsd.pkg.mk"
