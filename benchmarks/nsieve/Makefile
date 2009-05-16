# $NetBSD: Makefile,v 1.14 2009/05/16 20:46:19 zafer Exp $

DISTNAME=		nsieve.c
PKGNAME=		nsieve-1.2b
CATEGORIES=		benchmarks
MASTER_SITES=		ftp://ftp.kreonet.re.kr/tools/benchmark/aburto/nsieve/
EXTRACT_SUFX=		#empty

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Sieve of Eratosthenes benchmark

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

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
