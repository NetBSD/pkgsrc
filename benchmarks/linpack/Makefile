# $NetBSD: Makefile,v 1.1 1998/08/30 19:43:51 garbled Exp $

DISTNAME=		linpackc
PKGNAME=		linpack-940225
CATEGORIES=		benchmarks
MASTER_SITES=		http://www.netlib.org/benchmark/
EXTRACT_SUFX=		# empty

MAINTAINER=		root@garbled.net

NO_WRKSUBDIR=		yes

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${DISTDIR}/linpackc ${WRKSRC}/linpack.c

do-build:
	(cd ${WRKSRC} ; cc -O2 -DROLL -DDP -o linpackd linpack.c -lm)
	(cd ${WRKSRC} ; cc -O2 -DROLL -DSP -o linpacks linpack.c -lm)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/linpackd ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/linpacks ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
