# $NetBSD: Makefile,v 1.2 1998/09/23 17:00:35 agc Exp $

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

benchmark:
	-@${WRKSRC}/linpacks
	-@${WRKSRC}/linpackd

.include "../../mk/bsd.pkg.mk"
