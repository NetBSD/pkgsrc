# $NetBSD: Makefile,v 1.24 2023/03/12 02:49:45 gutteridge Exp $

VERSION=	8.1.0
DISTNAME=	music21-noCorpus-${VERSION}
PKGNAME=	${PYPKGPREFIX}-music21-${VERSION}
CATEGORIES=	audio python
MASTER_SITES=	${MASTER_SITE_GITHUB:=cuthbertLab/}
GITHUB_PROJECT=	music21
GITHUB_RELEASE=	v${VERSION}

MAINTAINER=	gutteridge@NetBSD.org
HOMEPAGE=	https://github.com/cuthbertLab/music21
COMMENT=	Python toolkit for computer-aided musical analysis
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling-[0-9]*:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-chardet-[0-9]*:../../converters/py-chardet
DEPENDS+=	${PYPKGPREFIX}-joblib-[0-9]*:../../devel/py-joblib
DEPENDS+=	${PYPKGPREFIX}-more-itertools-[0-9]*:../../devel/py-more-itertools
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-scipy-[0-9]*:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-Levenshtein-[0-9]*:../../textproc/py-Levenshtein
DEPENDS+=	${PYPKGPREFIX}-jsonpickle-[0-9]*:../../textproc/py-jsonpickle
DEPENDS+=	${PYPKGPREFIX}-webcolors>=1.11:../../www/py-webcolors

# Many tests will fail because they depend on the score files that
# are part of the full music21 distribution.
TEST_DEPENDS+=	${PYPKGPREFIX}-guppy3-[0-9]*:../../devel/py-guppy3

USE_LANGUAGES=	# none

# This package now only supports >= 3.8. (Same with its scipy dependency.)
# no 3.11 support in py-guppy3 as of 3.1.2
PYTHON_VERSIONS_INCOMPATIBLE=	27 37 311

# NB lilypond must be installed in order to run the full test suite.
do-test:
	PYTHONPATH=${WRKSRC} ${PYTHONBIN} -c 'from music21.test.testSingleCoreAll import ciMain as ci; ci()'

.include "options.mk"

.include "../../lang/python/wheel.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
