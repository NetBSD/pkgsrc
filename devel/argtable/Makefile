# $NetBSD: Makefile,v 1.1.1.1 2000/08/08 18:10:04 jlam Exp $

DISTNAME=	argtable-1.2
CATEGORIES=	devel
MASTER_SITES=	http://metalab.unc.edu/pub/Linux/devel/

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://metalab.unc.edu/pub/Linux/devel/argtable.html

GNU_CONFIGURE=	# defined

post-install:
	${INSTALL_DATA} ${WRKSRC}/man/man3/*.3 ${PREFIX}/man/man3
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/argtable
	${INSTALL_DATA} ${WRKSRC}/COPYING.LIB ${PREFIX}/share/doc/argtable

.include "../../mk/bsd.pkg.mk"
