# $NetBSD: Makefile,v 1.18 2016/04/24 10:34:43 wiz Exp $

DISTNAME=		nsieve.c
PKGNAME=		nsieve-1.2b
CATEGORIES=		benchmarks
MASTER_SITES=		#http://ftp.sunet.se/pub/benchmark/aburto/nsieve/
EXTRACT_SUFX=		#empty

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Sieve of Eratosthenes benchmark

WRKSRC=			${WRKDIR}

INSTALLATION_DIRS=	bin

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${DISTDIR}/nsieve.c ${WRKSRC}/nsieve.c

do-build:
	(cd ${WRKSRC} ; ${CC} ${CFLAGS} -DUNIX -o nsieve nsieve.c -lm)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nsieve ${DESTDIR}${PREFIX}/bin

benchmark:
	-@${WRKSRC}/nsieve | tee ${WRKSRC}/nsieve.out

results:
	@${MKDIR} /tmp/benches/`domainname`
	-@${CP} ${WRKSRC}/nsieve.out /tmp/benches/`domainname`/nsieve.`uname`-`uname -m`-`uname -r`.`hostname`

.include "../../mk/bsd.pkg.mk"
