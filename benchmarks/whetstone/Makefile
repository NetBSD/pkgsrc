# $NetBSD: Makefile,v 1.3 1998/09/24 09:19:10 agc Exp $

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

benchmark:
	@${WRKSRC}/whetstone

.include "../../mk/bsd.pkg.mk"
