# $NetBSD: Makefile,v 1.16 2010/01/25 00:32:23 zafer Exp $

DISTNAME=		heapsort.c
PKGNAME=		heapsort-1.0
CATEGORIES=		benchmarks
MASTER_SITES=	http://ftp.sunet.se/pub/benchmark/aburto/heapsort/
EXTRACT_SUFX=	#empty

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Benchmark program for variable sized arrays

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}

INSTALLATION_DIRS=	bin

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${DISTDIR}/heapsort.c ${WRKSRC}/heapsort.c

do-build:
	(cd ${WRKSRC} ; ${CC} ${CFLAGS} -DUNIX -o heapsort heapsort.c -lm)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/heapsort ${DESTDIR}${PREFIX}/bin

benchmark:
	-@${WRKSRC}/heapsort | tee ${WRKSRC}/heapsort.out

results:
	@${MKDIR} /tmp/benches/`domainname`
	-@${CP} ${WRKSRC}/heapsort.out /tmp/benches/`domainname`/heapsort.`uname`-`uname -m`-`uname -r`.`hostname`

.include "../../mk/bsd.pkg.mk"
