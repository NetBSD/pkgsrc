# $NetBSD: Makefile,v 1.4 2026/08/04 20:29:06 wiz Exp $

DISTNAME=	cadical-2.1.3
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

INSTALLATION_DIRS=	bin include/cadical lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/build/cadical ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/src/tracer.hpp ${DESTDIR}${PREFIX}/include/cadical
	${INSTALL_DATA} ${WRKSRC}/src/cadical.hpp ${DESTDIR}${PREFIX}/include/cadical
	${INSTALL_DATA} ${WRKSRC}/build/libcadical.a ${DESTDIR}${PREFIX}/lib

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../mk/bsd.pkg.mk"
