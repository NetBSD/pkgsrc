# $NetBSD: Makefile,v 1.13 2007/03/24 19:21:28 joerg Exp $

DISTNAME=	randlib.c-1.3
PKGNAME=	randlib-1.3
CATEGORIES=	math
MASTER_SITES=	ftp://odin.mdacc.tmc.edu/pub/source/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://odin.mdacc.tmc.edu/anonftp/
COMMENT=	Library of C Routines for Random Number Generation

DIST_SUBDIR=	${PKGNAME_NOREV}
WRKSRC=		${WRKDIR}/randlib.c/src

MAKE_ENV+=	LIBOWN=${LIBOWN:Q} LIBGRP=${LIBGRP:Q}

INSTALLATION_DIRS=	include lib share/doc/randlib share/examples/randlib

post-install:
	${INSTALL_DATA} ${WRKSRC}/../README ${WRKSRC}/../doc/* \
	${PREFIX}/share/doc/randlib
	${INSTALL_DATA} ${WRKSRC}/../test/* ${PREFIX}/share/examples/randlib
	${INSTALL_DATA} ${WRKSRC}/randlib.h ${PREFIX}/include

.include "../../mk/bsd.pkg.mk"
