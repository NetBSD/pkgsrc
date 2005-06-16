# $NetBSD: Makefile,v 1.3 2005/06/16 06:57:45 jlam Exp $
#

DISTNAME=	buddy22
PKGNAME=	buddy-2.2
CATEGORIES=	devel
MASTER_SITES=	http://www.itu.dk/research/buddy/

MAINTAINER=	kristerw@NetBSD.org
HOMEPAGE=	http://www.itu.dk/research/buddy/
COMMENT=	Library for binary decision diagrams

MAKEFILE=	makefile
BUILD_TARGET=	buddy

INSTALLATION_DIRS=	include lib

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/libbdd.a ${PREFIX}/lib
	${INSTALL_DATA}	${WRKSRC}/src/bdd.h ${WRKSRC}/src/fdd.h \
		${WRKSRC}/src/bvec.h ${PREFIX}/include
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/buddy
	${INSTALL_DATA} ${WRKSRC}/doc/*.ps ${WRKSRC}/doc/*.txt \
		${PREFIX}/share/doc/buddy

.include "../../mk/bsd.pkg.mk"
