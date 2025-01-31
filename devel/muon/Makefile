# $NetBSD: Makefile,v 1.1 2025/01/31 17:11:09 micha Exp $

PKGNAME=		muon-0.3.1
DISTNAME=		${PKGNAME:S/muon-//}
CATEGORIES=		devel
MASTER_SITES=		https://git.sr.ht/~lattis/muon/archive/
DIST_SUBDIR=		${PKGNAME_NOREV}
DISTFILES=		${DEFAULT_DISTFILES} man.tar.gz
SITES.man.tar.gz=	https://muon.build/releases/v${DISTNAME}/docs/

MAINTAINER=		micha@NetBSD.org
HOMEPAGE=		https://git.sr.ht/~lattis/muon
COMMENT=		Implementation of meson build system in C99 with minimal dependencies
LICENSE=		gnu-gpl-v3

USE_CC_FEATURES=	c99

# Use external samurai
CFLAGS+=		-DBOOTSTRAP_NO_SAMU
DEPENDS+=		samurai>=1.2:../../devel/samurai

# Required by some platforms for clock_gettime()
LDFLAGS+=		-lrt

MUON_ARGS+=		-Dlibcurl=disabled
MUON_ARGS+=		-Dlibarchive=disabled
MUON_ARGS+=		-Dlibpkgconf=enabled
MUON_ARGS+=		-Dsamurai=disabled
MUON_ARGS+=		-Dreadline=builtin
MUON_ARGS+=		-Dstatic=false
MUON_ARGS+=		-Ddocs=disabled
MUON_ARGS+=		-Dwebsite=false
MUON_ARGS+=		-Dtracy=disabled

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-configure:
	cd ${WRKSRC} && env ${CONFIGURE_ENV} ${CONFIG_SHELL} ./bootstrap.sh bootstrap
	cd ${WRKSRC} && env ${MAKE_ENV} ./bootstrap/muon setup ${MUON_ARGS} output

do-build:
	cd ${WRKSRC} && env ${MAKE_ENV} samu -j ${_MAKE_JOBS_N:U1} -C output

do-test:
	cd ${WRKSRC}/output && env ${TEST_ENV} ./muon test

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/output/muon ${DESTDIR}${PREFIX}/bin/muon
	${INSTALL_MAN} ${WRKDIR}/man/muon.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../devel/pkgconf/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
