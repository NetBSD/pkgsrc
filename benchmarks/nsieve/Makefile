# $NetBSD: Makefile,v 1.12 2008/01/19 09:16:18 wiz Exp $

DISTNAME=		nsieve.c
PKGNAME=		nsieve-1.2b
CATEGORIES=		benchmarks
MASTER_SITES=		ftp://ftp.nosc.mil/pub/aburto/nsieve/
EXTRACT_SUFX=		#empty

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Sieve of Eratosthenes benchmark

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}

INSTALLATION_DIRS=	bin

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${DISTDIR}/nsieve.c ${WRKSRC}/nsieve.c

do-build:
	(cd ${WRKSRC} ; ${CC} ${CFLAGS} -DUNIX -o nsieve nsieve.c -lm)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nsieve ${PREFIX}/bin

benchmark:
	-@${WRKSRC}/nsieve | tee ${WRKSRC}/nsieve.out

results:
	@${MKDIR} /tmp/benches/`domainname`
	-@${CP} ${WRKSRC}/nsieve.out /tmp/benches/`domainname`/nsieve.`uname`-`uname -m`-`uname -r`.`hostname`

.include "../../mk/bsd.pkg.mk"
