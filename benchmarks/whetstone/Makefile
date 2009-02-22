# $NetBSD: Makefile,v 1.18 2009/02/22 14:15:28 asau Exp $

DISTNAME=		whetstone
PKGNAME=		whetstone-1.2
CATEGORIES=		benchmarks
MASTER_SITES=		${MASTER_SITE_NETLIB:=benchmark/}
EXTRACT_SUFX=		.c

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Benchmark for processors that gives you a MIPS rating

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}

INSTALLATION_DIRS=	bin

do-build:
	(cd ${WRKSRC} ; ${CC} ${CFLAGS} -o whetstone whetstone.c -lm)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/whetstone ${DESTDIR}${PREFIX}/bin

benchmark:
	@${WRKSRC}/whetstone 80000 | tee ${WRKSRC}/whetstone.out

results:
	@${MKDIR} /tmp/benches/`domainname`
	-@${CP} ${WRKSRC}/whetstone.out /tmp/benches/`domainname`/whetstone.`uname`-`uname -m`-`uname -r`.`hostname`

.include "../../mk/bsd.pkg.mk"
