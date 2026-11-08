# $NetBSD: Makefile,v 1.6 2026/11/08 16:01:00 wiz Exp $

DISTNAME=	cadical-2.1.3
PKGREVISION=	2
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=arminbiere/}
GITHUB_TAG=	rel-${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/arminbiere/cadical/
COMMENT=	SAT Solver (v2)
LICENSE=	mit

WRKSRC=		${WRKDIR}/cadical-rel-${PKGVERSION_NOREV}
HAS_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake
MAKE_FILE=	makefile
TEST_TARGET=	test

INSTALLATION_DIRS=	bin include/cadical lib lib/pkgconfig

SUBST_CLASSES+=		pc
SUBST_STAGE.pc=		pre-configure
SUBST_MESSAGE.pc=	Set prefix and version in cadical.pc.
SUBST_FILES.pc=		cadical.pc
SUBST_VARS.pc=		PREFIX PKGVERSION_NOREV

# LDFLAGS are ignored, but this works
# https://github.com/arminbiere/cadical/pull/88#issuecomment-5073528194
CONFIGURE_ARGS+=	${LDFLAGS}

post-extract:
	${CP} ${FILESDIR}/cadical.pc ${WRKSRC}/cadical.pc

do-install:
	${INSTALL_DATA} ${WRKSRC}/cadical.pc ${DESTDIR}${PREFIX}/lib/pkgconfig
	${INSTALL_PROGRAM} ${WRKSRC}/build/cadical ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/src/tracer.hpp ${DESTDIR}${PREFIX}/include/cadical
	${INSTALL_DATA} ${WRKSRC}/src/cadical.hpp ${DESTDIR}${PREFIX}/include/cadical
	${INSTALL_DATA} ${WRKSRC}/build/libcadical.a ${DESTDIR}${PREFIX}/lib

.include "../../mk/bsd.pkg.mk"
