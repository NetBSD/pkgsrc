# $NetBSD: Makefile,v 1.1.1.1 2003/12/31 00:04:19 kristerw Exp $
#

DISTNAME=	buddy22
PKGNAME=	buddy-2.2
CATEGORIES=	devel
MASTER_SITES=	http://www.itu.dk/research/buddy/

MAINTAINER=	kristerw@NetBSD.org
HOMEPAGE=	http://www.itu.dk/research/buddy/
COMMENT=	Library for binary decision diagrams

MAKEFILE=	makefile
ALL_TARGET=	buddy

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/libbdd.a ${PREFIX}/lib
	${INSTALL_DATA}	${WRKSRC}/src/bdd.h ${WRKSRC}/src/fdd.h \
		${WRKSRC}/src/bvec.h ${PREFIX}/include
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/buddy
	${INSTALL_DATA} ${WRKSRC}/doc/*.ps ${WRKSRC}/doc/*.txt \
		${PREFIX}/share/doc/buddy

.include "../../mk/bsd.pkg.mk"
