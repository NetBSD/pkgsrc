# $NetBSD: Makefile,v 1.15 2012/10/31 11:16:37 asau Exp $

DISTNAME=	argtable-1.2
CATEGORIES=	devel
MASTER_SITES=	http://www.ibiblio.org/pub/Linux/devel/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ibiblio.org/pub/Linux/devel/argtable.html
COMMENT=	Library for parsing command line arguments of a C/C++ program

GNU_CONFIGURE=		YES

USE_LANGUAGES=	c c++

INSTALLATION_DIRS=	include lib ${PKGMANDIR}/man3 share/doc/argtable

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/argtable.h ${DESTDIR}${PREFIX}/include
	${INSTALL_LIB} ${WRKSRC}/src/libargtable.a ${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/man/man3/*.3 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man3
	${INSTALL_DATA} ${WRKSRC}/COPYING.LIB ${DESTDIR}${PREFIX}/share/doc/argtable

.include "../../mk/bsd.pkg.mk"
