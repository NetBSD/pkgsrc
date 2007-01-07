# $NetBSD: Makefile,v 1.13 2007/01/07 09:13:50 rillig Exp $

DISTNAME=	argtable-1.2
CATEGORIES=	devel
MASTER_SITES=	http://www.ibiblio.org/pub/Linux/devel/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ibiblio.org/pub/Linux/devel/argtable.html
COMMENT=	Library for parsing command line arguments of a C/C++ program

GNU_CONFIGURE=		YES

USE_LANGUAGES=	c c++

INSTALLATION_DIRS=	include lib ${PKGMANDIR}/man3 share/doc/argtable

post-install:
	${INSTALL_DATA} ${WRKSRC}/man/man3/*.3 ${PREFIX}/${PKGMANDIR}/man3
	${INSTALL_DATA} ${WRKSRC}/COPYING.LIB ${PREFIX}/share/doc/argtable

.include "../../mk/bsd.pkg.mk"
