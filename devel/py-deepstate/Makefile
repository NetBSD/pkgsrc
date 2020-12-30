# $NetBSD: Makefile,v 1.2 2020/12/30 12:29:24 nia Exp $

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}

USE_LANGUAGES=	c99 c++
USE_CMAKE=	yes
AUTO_MKDIRS=	yes

DEPENDS+=	deepstate>=${VERSION}:../../devel/deepstate
DEPENDS+=	deepstate-afl>=${VERSION}:../../devel/deepstate-afl
#XXX seems to not build on NetBSD
#DEPENDS+=	deepstate-honggfuzz>=${VERSION}:../../devel/deepstate-honggfuzz
DEPENDS+=	deepstate-libfuzzer>=${VERSION}:../../devel/deepstate-libfuzzer

PYTHON_VERSIONS_INCOMPATIBLE=	27

CONFIGURE_DIRS=	build
CMAKE_ARG_PATH=	${WRKSRC}
PYSETUPSUBDIR=	build

pre-configure:
	cd ${WRKSRC} && ${MKDIR} ${CONFIGURE_DIRS}

.include "../../devel/deepstate/Makefile.common"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
