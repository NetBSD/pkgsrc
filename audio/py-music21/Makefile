# $NetBSD: Makefile,v 1.4 2020/03/30 23:21:41 gutteridge Exp $

VERSION=	5.7.2
DISTNAME=	music21-noCorpus-${VERSION}
PKGNAME=	${PYPKGPREFIX}-music21-${VERSION}
PKGREVISION=	1
CATEGORIES=	audio python
MASTER_SITES=	${MASTER_SITE_GITHUB:=cuthbertLab/}
GITHUB_PROJECT=	music21
GITHUB_RELEASE=	v${VERSION}

MAINTAINER=	gutteridge@NetBSD.org
HOMEPAGE=	https://github.com/cuthbertLab/music21
COMMENT=	Python toolkit for computer-aided musical analysis
LICENSE=	modified-bsd OR gnu-lgpl-v3

# 5.7.2 has partial support for Python 3.8.
PYTHON_VERSIONS_INCOMPATIBLE=	27

EGG_NAME=	music21-${VERSION}

DEPENDS+=	${PYPKGPREFIX}-game-[0-9]*:../../devel/py-game
DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-scipy-[0-9]*:../../math/py-scipy

# Many tests will fail because they depend on the score files that
# are part of the full music21 distribution. The entire test suite
# will also fail to run with Python < 3.8 as of 5.7.2, due to:
# https://github.com/cuthbertLab/music21/issues/507
TEST_DEPENDS+=	${PYPKGPREFIX}-guppy3-[0-9]*:../../devel/py-guppy3

USE_LANGUAGES=	# none

.include "options.mk"

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
