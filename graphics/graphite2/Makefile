# $NetBSD: Makefile,v 1.22 2025/12/25 09:21:47 wiz Exp $

DISTNAME=	graphite2-1.3.14
PKGREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=silgraphite/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://graphite.sil.org/
COMMENT=	Cross-platform rendering for complex writing systems
LICENSE=	gnu-lgpl-v2

USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

USE_CXX_FEATURES+=	c++11

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
# Linux seems to need this to build by default, but apparently it is
# only used for test, so for now use 'build' dependency
BUILDLINK_DEPMETHOD.freetype2?=	build
.include "../../graphics/freetype2/buildlink3.mk"
.endif

# python and py-fonttools seem to be used only during test
# uncomment the following to do so
#TEST_TARGET=	test
#PYTHON_FOR_BUILD_ONLY?=	tool
#.include "../../lang/python/tool.mk"
#TOOL_DEPENDS+=	${PYPKGPREFIX}-fonttools-[0-9]*:../../fonts/py-fonttools/

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
