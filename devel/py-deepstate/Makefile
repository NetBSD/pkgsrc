# $NetBSD: Makefile,v 1.5 2022/11/14 14:34:48 wiz Exp $

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2

USE_LANGUAGES=	c99 c++
USE_CMAKE=	yes
AUTO_MKDIRS=	yes

DEPENDS+=	deepstate>=${VERSION}:../../devel/deepstate
DEPENDS+=	deepstate-afl>=${VERSION}:../../devel/deepstate-afl
#XXX seems to not build on NetBSD
#DEPENDS+=	deepstate-honggfuzz>=${VERSION}:../../devel/deepstate-honggfuzz
DEPENDS+=	deepstate-libfuzzer>=${VERSION}:../../devel/deepstate-libfuzzer

PYTHON_VERSIONS_INCOMPATIBLE=	27 311

USE_PKG_RESOURCES=	yes

CONFIGURE_DIRS=	build
CMAKE_ARG_PATH=	${WRKSRC}
PYSETUPSUBDIR=	build

pre-configure:
	cd ${WRKSRC} && ${MKDIR} ${CONFIGURE_DIRS}

.include "../../devel/deepstate/Makefile.common"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
