# $NetBSD: Makefile,v 1.3 2002/04/19 18:12:57 jlam Exp $

DISTNAME=	argtable-1.2
CATEGORIES=	devel
MASTER_SITES=	http://metalab.unc.edu/pub/Linux/devel/

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://metalab.unc.edu/pub/Linux/devel/argtable.html
COMMENT=	library for parsing command line arguments of a C/C++ program

USE_BUILDINK_ONLY=	YES
GNU_CONFIGURE=		YES

post-install:
	${INSTALL_DATA} ${WRKSRC}/man/man3/*.3 ${PREFIX}/man/man3
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/argtable
	${INSTALL_DATA} ${WRKSRC}/COPYING.LIB ${PREFIX}/share/doc/argtable

.include "../../mk/bsd.pkg.mk"
