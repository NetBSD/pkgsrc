# $NetBSD: Makefile,v 1.3 1999/03/16 09:02:27 agc Exp $

DISTNAME=		nsieve.c
PKGNAME=		nsieve-1.2b
CATEGORIES=		benchmarks
MASTER_SITES=		ftp://ftp.nosc.mil/pub/aburto/nsieve/
EXTRACT_SUFX=		#empty

MAINTAINER=		root@garbled.net

NO_WRKSUBDIR=		yes

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${DISTDIR}/nsieve.c ${WRKSRC}/nsieve.c

do-build:
	(cd ${WRKSRC} ; ${CC} -O2 -DUNIX -o nsieve nsieve.c -lm)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nsieve ${PREFIX}/bin

benchmark:
	-@${WRKSRC}/nsieve | tee ${WRKSRC}/nsieve.out

results:
	-@${MKDIR} /tmp/benches/`domainname`
	-@cp ${WRKSRC}/nsieve.out /tmp/benches/`domainname`/nsieve.`uname`-`uname -m`-`uname -r`.`hostname`

.include "../../mk/bsd.pkg.mk"
