# $NetBSD: Makefile,v 1.12 2008/01/19 09:16:18 wiz Exp $

DISTNAME=		flops
PKGNAME=		flops-2.0
CATEGORIES=		benchmarks
MASTER_SITES=		ftp://ftp.nosc.mil/pub/aburto/flops/
DISTFILES=		${DISTNAME}.c ${DISTNAME}.doc

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://performance.netlib.org/performance/html/flops.html
COMMENT=		Floating point benchmark to give your MFLOPS rating

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}

INSTALLATION_DIRS=	bin

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${DISTDIR}/flops.c ${WRKSRC}/flops.c
	${CP} ${DISTDIR}/flops.doc ${WRKSRC}/flops.doc

do-build:
	(cd ${WRKSRC} ; ${CC} ${CFLAGS} -DUNIX -o flops flops.c -lm)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/flops ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/flops
	${INSTALL_DATA} ${WRKSRC}/flops.doc ${PREFIX}/share/doc/flops

benchmark:
	-@${WRKSRC}/flops | tee ${WRKSRC}/flops.out

results:
	@${MKDIR} /tmp/benches/`domainname`
	-@${CP} ${WRKSRC}/flops.out /tmp/benches/`domainname`/flops.`uname`-`uname -m`-`uname -r`.`hostname`

.include "../../mk/bsd.pkg.mk"
