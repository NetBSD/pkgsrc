# $NetBSD: Makefile,v 1.11 2004/01/20 12:08:12 agc Exp $

DISTNAME=		heapsort.c
PKGNAME=		heapsort-1.0
CATEGORIES=		benchmarks
MASTER_SITES=		ftp://ftp.nosc.mil/pub/aburto/heapsort/
EXTRACT_SUFX=		#empty

MAINTAINER=		root@garbled.net
COMMENT=		Benchmark program for variable sized arrays

WRKSRC=			${WRKDIR}

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${DISTDIR}/heapsort.c ${WRKSRC}/heapsort.c

do-build:
	(cd ${WRKSRC} ; ${CC} ${CFLAGS} -DUNIX -o heapsort heapsort.c -lm)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/heapsort ${PREFIX}/bin

benchmark:
	-@${WRKSRC}/heapsort | tee ${WRKSRC}/heapsort.out

results:
	@${MKDIR} /tmp/benches/`domainname`
	-@${CP} ${WRKSRC}/heapsort.out /tmp/benches/`domainname`/heapsort.`uname`-`uname -m`-`uname -r`.`hostname`

.include "../../mk/bsd.pkg.mk"
