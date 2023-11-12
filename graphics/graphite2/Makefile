# $NetBSD: Makefile,v 1.20 2023/11/12 13:22:01 wiz Exp $

DISTNAME=	graphite2-1.3.14
PKGREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=silgraphite/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://graphite.sil.org/
COMMENT=	Cross-platform rendering for complex writing systems
LICENSE=	gnu-lgpl-v2

USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

USE_CXX_FEATURES+=	c++11

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
# Linux seems to need this to build by default, but apparently it is
# only used for test, so for now use 'build' dependency
BUILDLINK_DEPMETHOD.freetype2?=	build
.include "../../graphics/freetype2/buildlink3.mk"
.endif

# python and py-fonttools seem to be used only during test
# uncomment the following to do so
#TEST_TARGET=			test
#PYTHON_FOR_BUILD_ONLY?=	tool
#.include "../../lang/python/tool.mk"
#TOOL_DEPENDS+=		${PYPKGPREFIX}-fonttools-[0-9]*:../../fonts/py-fonttools/

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
