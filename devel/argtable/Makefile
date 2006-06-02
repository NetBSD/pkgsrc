# $NetBSD: Makefile,v 1.11 2006/06/02 15:34:12 joerg Exp $

DISTNAME=	argtable-1.2
CATEGORIES=	devel
MASTER_SITES=	http://metalab.unc.edu/pub/Linux/devel/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://metalab.unc.edu/pub/Linux/devel/argtable.html
COMMENT=	Library for parsing command line arguments of a C/C++ program

GNU_CONFIGURE=		YES

USE_LANGUAGES=	c c++

INSTALLATION_DIRS=	include lib man/man3 share/doc/argtable

post-install:
	${INSTALL_DATA} ${WRKSRC}/man/man3/*.3 ${PREFIX}/man/man3
	${INSTALL_DATA} ${WRKSRC}/COPYING.LIB ${PREFIX}/share/doc/argtable

.include "../../mk/bsd.pkg.mk"
