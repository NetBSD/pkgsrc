# $NetBSD: Makefile,v 1.10 2004/01/20 12:20:05 agc Exp $

DISTNAME=	randlib.c-1.3
PKGNAME=	randlib-1.3
CATEGORIES=	math
MASTER_SITES=	ftp://odin.mdacc.tmc.edu/pub/source/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://odin.mdacc.tmc.edu/anonftp/
COMMENT=	Library of C Routines for Random Number Generation

DIST_SUBDIR=	${PKGNAME_NOREV}
WRKSRC=		${WRKDIR}/randlib.c/src

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/randlib
	${INSTALL_DATA} ${WRKSRC}/../README ${WRKSRC}/../doc/* \
	${PREFIX}/share/doc/randlib
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/randlib
	${INSTALL_DATA} ${WRKSRC}/../test/* ${PREFIX}/share/examples/randlib
	${INSTALL_DATA} ${WRKSRC}/randlib.h ${PREFIX}/include

.include "../../mk/bsd.pkg.mk"
