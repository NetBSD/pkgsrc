# $NetBSD: Makefile,v 1.18 2016/04/24 10:34:43 wiz Exp $

DISTNAME=		fib.c
PKGNAME=		fib-980203
CATEGORIES=		benchmarks
MASTER_SITES=		# http://ftp.sunet.se/pub/benchmark/aburto/fib/
EXTRACT_SUFX=		#empty

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Mathematical benchmark

WRKSRC=			${WRKDIR}

INSTALLATION_DIRS=	bin

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${DISTDIR}/fib.c ${WRKSRC}/fib.c

do-build:
	(cd ${WRKSRC} ; ${CC} ${CFLAGS} -DUNIX -o fib fib.c -lm)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fib ${DESTDIR}${PREFIX}/bin

benchmark:
	-@${WRKSRC}/fib | tee ${WRKSRC}/fib.out

results:
	@${MKDIR} /tmp/benches/`domainname`
	-@${CP} ${WRKSRC}/fib.out /tmp/benches/`domainname`/fib.`uname`-`uname -m`-`uname -r`.`hostname`

.include "../../mk/bsd.pkg.mk"
