# $NetBSD: Makefile,v 1.1 2026/07/24 18:38:00 wiz Exp $

DISTNAME=	cadical-3.0.1
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=arminbiere/}
GITHUB_TAG=	rel-${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/arminbiere/cadical/
COMMENT=	SAT Solver
LICENSE=	mit

WRKSRC=			${WRKDIR}/cadical-rel-${PKGVERSION_NOREV}
HAS_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_CC_FEATURES=	c99
USE_CXX_FEATURES=	c++11
USE_TOOLS+=		gmake
MAKE_FILE=		makefile

INSTALLATION_DIRS=	bin include lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/build/cadical ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/src/cadical.hpp ${DESTDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/build/libcadical.a ${DESTDIR}${PREFIX}/lib

.include "../../mk/bsd.pkg.mk"
