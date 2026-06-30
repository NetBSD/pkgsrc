# $NetBSD: Makefile,v 1.2 2026/06/30 22:52:48 alnsn Exp $

DISTNAME=	cadical-2.1.3
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=arminbiere/}
GITHUB_TAG=	rel-${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/arminbiere/cadical/
COMMENT=	SAT Solver
LICENSE=	mit

WRKSRC=		${WRKDIR}/cadical-rel-${PKGVERSION_NOREV}
HAS_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake
MAKE_FILE=	makefile
TEST_TARGET=	test

INSTALLATION_DIRS=	bin include/cadical lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/build/cadical ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/src/tracer.hpp ${DESTDIR}${PREFIX}/include/cadical
	${INSTALL_DATA} ${WRKSRC}/src/cadical.hpp ${DESTDIR}${PREFIX}/include/cadical
	${INSTALL_DATA} ${WRKSRC}/build/libcadical.a ${DESTDIR}${PREFIX}/lib

.include "../../mk/bsd.pkg.mk"
