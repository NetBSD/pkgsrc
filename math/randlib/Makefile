# $NetBSD: Makefile,v 1.5 2003/03/29 12:41:44 jmmv Exp $

DISTNAME=	randlib.c-1.3
PKGNAME=	randlib-1.3
WRKSRC=		${WRKDIR}/randlib.c/src
CATEGORIES=	math
MASTER_SITES=	ftp://odin.mdacc.tmc.edu/pub/source/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://odin.mdacc.tmc.edu/anonftp/page_2.html
COMMENT=	Library of C Routines for Random Number Generation

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/randlib
	${INSTALL_DATA} ${WRKSRC}/../README ${WRKSRC}/../doc/* \
	${PREFIX}/share/doc/randlib
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/randlib
	${INSTALL_DATA} ${WRKSRC}/../test/* ${PREFIX}/share/examples/randlib
	${INSTALL_DATA} ${WRKSRC}/randlib.h ${PREFIX}/include

.include "../../mk/bsd.pkg.mk"
