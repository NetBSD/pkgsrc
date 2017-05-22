# $NetBSD: Makefile,v 1.6 2017/05/22 08:00:06 he Exp $

DISTNAME=	graphite2-1.3.10
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=silgraphite/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/silgraphite/
COMMENT=	Cross-platform rendering for complex writing systems
LICENSE=	gnu-lgpl-v2

USE_LANGUAGES=	c c++
USE_CMAKE=	yes
USE_LIBTOOL=	yes

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
#BUILD_DEPENDS+=	${PYPKGPREFIX}-fonttools-[0-9]*:../../fonts/py-fonttools/

.include "../../mk/bsd.pkg.mk"
