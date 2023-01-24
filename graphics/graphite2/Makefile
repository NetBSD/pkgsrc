# $NetBSD: Makefile,v 1.15 2023/01/24 18:36:26 wiz Exp $

DISTNAME=	graphite2-1.3.14
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=silgraphite/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://graphite.sil.org/
COMMENT=	Cross-platform rendering for complex writing systems
LICENSE=	gnu-lgpl-v2

USE_LANGUAGES=	c c++11
USE_LIBTOOL=	yes

# C++11
GCC_REQD+=	4.8

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
#BUILD_DEPENDS+=		${PYPKGPREFIX}-fonttools-[0-9]*:../../fonts/py-fonttools/

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
