# $NetBSD: Makefile,v 1.6 2001/03/31 10:09:04 zuntum Exp $

DISTNAME=		fib.c
PKGNAME=		fib-980203
CATEGORIES=		benchmarks
MASTER_SITES=		ftp://ftp.nosc.mil/pub/aburto/fib/
EXTRACT_SUFX=		#empty

MAINTAINER=		root@garbled.net
COMMENT=		Mathematical benchmark

NO_WRKSUBDIR=		yes

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${DISTDIR}/fib.c ${WRKSRC}/fib.c

do-build:
	(cd ${WRKSRC} ; ${CC} ${CFLAGS} -DUNIX -o fib fib.c -lm)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fib ${PREFIX}/bin

benchmark:
	-@${WRKSRC}/fib | tee ${WRKSRC}/fib.out

results:
	-@${MKDIR} /tmp/benches/`domainname`
	-@${CP} ${WRKSRC}/fib.out /tmp/benches/`domainname`/fib.`uname`-`uname -m`-`uname -r`.`hostname`

.include "../../mk/bsd.pkg.mk"
