# $NetBSD: Makefile,v 1.3 1998/12/26 15:59:56 garbled Exp $

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
	-@${WRKSRC}/linpacks | tee ${WRKSRC}/linpacks.out
	-@${WRKSRC}/linpackd | tee ${WRKSRC}/linpackd.out

results:
	-@${MKDIR} /tmp/benches/`domainname`
	-@cp ${WRKSRC}/linpacks.out /tmp/benches/`domainname`/linpacks.`uname`-`uname -m`-`uname -r`.`hostname`
	-@cp ${WRKSRC}/linpackd.out /tmp/benches/`domainname`/linpackd.`uname`-`uname -m`-`uname -r`.`hostname`

.include "../../mk/bsd.pkg.mk"
