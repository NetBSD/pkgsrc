# $NetBSD: Makefile,v 1.6 2026/07/03 14:36:21 micha Exp $

DISTNAME=		muon-v0.6.0
PKGNAME=		${DISTNAME:S/v//}
CATEGORIES=		devel
MASTER_SITES=		https://muon.build/releases/${DISTNAME:S/muon-//}/
DIST_SUBDIR=		${PKGNAME_NOREV}
DISTFILES=		${DEFAULT_DISTFILES} man.tar.gz
SITES.man.tar.gz=	https://muon.build/releases/${DISTNAME:S/muon-//}/docs/

MAINTAINER=		micha@NetBSD.org
HOMEPAGE=		https://git.sr.ht/~lattis/muon
COMMENT=		Implementation of meson build system in C99 with minimal dependencies
LICENSE=		gnu-gpl-v3

USE_TOOLS=		pkg-config
USE_CC_FEATURES=	c99

# Use external samurai
CFLAGS+=		-DBOOTSTRAP_NO_SAMU
DEPENDS+=		samurai>=1.2:../../devel/samurai

# Required for clock_gettime() from GNU libc <2.17
LDFLAGS.Linux+=		-lrt

# [On SmartOS] ld: fatal: unrecognized option '--as-needed'
BUILDLINK_TRANSFORM.SunOS+=	opt:-Wl,--as-needed:-Wl,-zignore
BUILDLINK_TRANSFORM.SunOS+=	opt:-Wl,--no-as-needed:-Wl,-zrecord

MUON_ARGS+=		-Dlibcurl=disabled
MUON_ARGS+=		-Dlibarchive=disabled
MUON_ARGS+=		-Dlibpkgconf=disabled
MUON_ARGS+=		-Dsamurai=disabled
MUON_ARGS+=		-Dtracy=disabled
MUON_ARGS+=		-Dui=disabled
MUON_ARGS+=		-Dreadline=builtin
MUON_ARGS+=		-Dstatic=false
MUON_ARGS+=		-Dman-pages=disabled
MUON_ARGS+=		-Dmeson-docs=disabled
MUON_ARGS+=		-Dmeson-tests=disabled
MUON_ARGS+=		-Dwebsite=disabled

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-configure:
	cd ${WRKSRC} && env ${CONFIGURE_ENV} ${RM} -f subprojects/meson-tests.wrap
	cd ${WRKSRC} && env ${CONFIGURE_ENV} ${CONFIG_SHELL} ./bootstrap.sh bootstrap
	cd ${WRKSRC} && env ${MAKE_ENV} ./bootstrap/muon-bootstrap setup ${MUON_ARGS} output

do-build:
	cd ${WRKSRC} && env ${MAKE_ENV} samu -j ${_MAKE_JOBS_N:U1} -C output

do-test:
	cd ${WRKSRC}/output && env ${TEST_ENV} ./muon test

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/output/muon ${DESTDIR}${PREFIX}/bin/muon
	${INSTALL_MAN} ${WRKDIR}/man/muon.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
