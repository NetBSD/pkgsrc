# $NetBSD: Makefile,v 1.39 2025/12/21 17:28:17 wiz Exp $

DISTNAME=	re2c-4.4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=skvadrik/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://re2c.org/
COMMENT=	Deterministic Finite State Automaton generator
LICENSE=	public-domain

USE_CXX_FEATURES=	c++11
USE_LANGUAGES=		c c++
USE_TOOLS+=		bison
TEST_TARGET=		check
PYTHON_FOR_BUILD_ONLY=	tool

.include "../../mk/bsd.prefs.mk"

SUBST_CLASSES+=		man
SUBST_SED.man+=		-e "s,share/man/man1,${PKGMANDIR}/man1,"
SUBST_FILES.man+=	CMakeLists.txt
SUBST_STAGE.man=	pre-configure
SUBST_MESSAGE.man=	Fixing man page path.

# can't use ninja, since ninja tool-depends on this
CMAKE_GENERATORS_INCOMPATIBLE=	ninja

.include "../../devel/cmake/build.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
