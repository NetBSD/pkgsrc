# $NetBSD: Makefile,v 1.1.1.1 2001/04/27 22:29:38 jtb Exp $

DISTNAME=		linpackc
PKGNAME=		linpack-bench-940225
CATEGORIES=		benchmarks
MASTER_SITES=		http://www.netlib.org/benchmark/
EXTRACT_SUFX=		# empty

MAINTAINER=		root@garbled.net
COMMENT=		Collection of benchmarks for floating point

NO_WRKSUBDIR=		yes

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${DISTDIR}/linpackc ${WRKSRC}/linpack.c

do-build:
	(cd ${WRKSRC} ; ${CC} ${CFLAGS} -DROLL -DDP -o linpackd linpack.c -lm)
	(cd ${WRKSRC} ; ${CC} ${CFLAGS} -DROLL -DSP -o linpacks linpack.c -lm)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/linpackd ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/linpacks ${PREFIX}/bin

benchmark:
	-@${WRKSRC}/linpacks | tee ${WRKSRC}/linpacks.out
	-@${WRKSRC}/linpackd | tee ${WRKSRC}/linpackd.out

results:
	@${MKDIR} /tmp/benches/`domainname`
	-@${CP} ${WRKSRC}/linpacks.out /tmp/benches/`domainname`/linpacks.`uname`-`uname -m`-`uname -r`.`hostname`
	-@${CP} ${WRKSRC}/linpackd.out /tmp/benches/`domainname`/linpackd.`uname`-`uname -m`-`uname -r`.`hostname`

.include "../../mk/bsd.pkg.mk"
