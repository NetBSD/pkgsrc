# $NetBSD: Makefile,v 1.1.1.1 1998/10/22 05:55:46 garbled Exp $

DISTNAME=		fib.c
PKGNAME=		fib-980203
CATEGORIES=		benchmarks
MASTER_SITES=		ftp://ftp.nosc.mil/pub/aburto/fib/
EXTRACT_SUFX=		#empty

MAINTAINER=		root@garbled.net

NO_WRKSUBDIR=		yes

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${DISTDIR}/fib.c ${WRKSRC}/fib.c

do-build:
	(cd ${WRKSRC} ; cc -O2 -DUNIX -o fib fib.c -lm)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fib ${PREFIX}/bin

benchmark:
	-@${WRKSRC}/fib

.include "../../mk/bsd.pkg.mk"
