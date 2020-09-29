# $NetBSD: Makefile,v 1.1 2020/09/29 03:12:44 khorben Exp $

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}

USE_LANGUAGES=	c99 c++
USE_CMAKE=	yes
AUTO_MKDIRS=	yes

DEPENDS+=	deepstate>=${VERSION}:../../devel/deepstate
DEPENDS+=	deepstate-afl>=${VERSION}:../../devel/deepstate-afl
#XXX seems to not build on NetBSD
#DEPENDS+=	deepstate-honggfuzz>=${VERSION}:../../devel/deepstate-honggfuzz
DEPENDS+=	deepstate-libfuzzer>=${VERSION}:../../devel/deepstate-libfuzzer

PYTHON_VERSIONS_ACCEPTED=	37 36

CONFIGURE_DIRS=	build
CMAKE_ARG_PATH=	${WRKSRC}
PYSETUPSUBDIR=	build

pre-configure:
	cd ${WRKSRC} && ${MKDIR} ${CONFIGURE_DIRS}

.include "../../devel/deepstate/Makefile.common"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
