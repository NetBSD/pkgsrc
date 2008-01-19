# $NetBSD: Makefile,v 1.16 2008/01/19 09:16:19 wiz Exp $

DISTNAME=		whetstone
PKGNAME=		whetstone-1.2
CATEGORIES=		benchmarks
MASTER_SITES=		http://www.netlib.org/benchmark/
EXTRACT_SUFX=		.c

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Benchmark for processors that gives you a MIPS rating

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}

INSTALLATION_DIRS=	bin

do-build:
	(cd ${WRKSRC} ; ${CC} ${CFLAGS} -o whetstone whetstone.c -lm)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/whetstone ${PREFIX}/bin

benchmark:
	@${WRKSRC}/whetstone 80000 | tee ${WRKSRC}/whetstone.out

results:
	@${MKDIR} /tmp/benches/`domainname`
	-@${CP} ${WRKSRC}/whetstone.out /tmp/benches/`domainname`/whetstone.`uname`-`uname -m`-`uname -r`.`hostname`

.include "../../mk/bsd.pkg.mk"
