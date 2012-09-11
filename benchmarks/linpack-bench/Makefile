# $NetBSD: Makefile,v 1.9 2012/09/11 22:37:13 asau Exp $

DISTNAME=		linpackc
PKGNAME=		linpack-bench-940225
CATEGORIES=		benchmarks
MASTER_SITES=		${MASTER_SITE_NETLIB:=benchmark/}
EXTRACT_SUFX=		# empty

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Collection of benchmarks for floating point

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}

INSTALLATION_DIRS=	bin

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${DISTDIR}/linpackc ${WRKSRC}/linpack.c

do-build:
	(cd ${WRKSRC} ; ${CC} ${CFLAGS} -DROLL -DDP -o linpackd linpack.c -lm)
	(cd ${WRKSRC} ; ${CC} ${CFLAGS} -DROLL -DSP -o linpacks linpack.c -lm)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/linpackd ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/linpacks ${DESTDIR}${PREFIX}/bin

benchmark:
	-@${WRKSRC}/linpacks | tee ${WRKSRC}/linpacks.out
	-@${WRKSRC}/linpackd | tee ${WRKSRC}/linpackd.out

results:
	@${MKDIR} /tmp/benches/`domainname`
	-@${CP} ${WRKSRC}/linpacks.out /tmp/benches/`domainname`/linpacks.`uname`-`uname -m`-`uname -r`.`hostname`
	-@${CP} ${WRKSRC}/linpackd.out /tmp/benches/`domainname`/linpackd.`uname`-`uname -m`-`uname -r`.`hostname`

.include "../../mk/bsd.pkg.mk"
