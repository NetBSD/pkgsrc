# $NetBSD: Makefile,v 1.2 1998/09/06 21:11:24 garbled Exp $

DISTNAME=		whetstone
PKGNAME=		whetstone-1.2
CATEGORIES=		benchmarks
MASTER_SITES=		http://www.netlib.org/benchmark/
EXTRACT_SUFX=		.c

MAINTAINER=		root@garbled.net

NO_WRKSUBDIR=		yes
EXTRACT_CMD=		${CP}
EXTRACT_BEFORE_ARGS=	#empty
EXTRACT_AFTER_ARGS=	${WRKSRC}

do-build:
	(cd ${WRKSRC} ; cc -O2 -o whetstone whetstone.c -lm)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/whetstone ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
