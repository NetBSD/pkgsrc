# $NetBSD: Makefile,v 1.17 2022/04/04 01:51:59 gutteridge Exp $

VERSION=	7.3.1
DISTNAME=	music21-noCorpus-${VERSION}
PKGNAME=	${PYPKGPREFIX}-music21-${VERSION}
CATEGORIES=	audio python
MASTER_SITES=	${MASTER_SITE_GITHUB:=cuthbertLab/}
GITHUB_PROJECT=	music21
# A bug fix 7.3.1 release was made, but tagged as release 7.3.0.
GITHUB_RELEASE=	v${VERSION:R}.0

MAINTAINER=	gutteridge@NetBSD.org
HOMEPAGE=	https://github.com/cuthbertLab/music21
COMMENT=	Python toolkit for computer-aided musical analysis
LICENSE=	modified-bsd OR gnu-lgpl-v3

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-scipy

EGG_NAME=	music21-${VERSION}

DEPENDS+=	${PYPKGPREFIX}-chardet-[0-9]*:../../converters/py-chardet
DEPENDS+=	${PYPKGPREFIX}-joblib-[0-9]*:../../devel/py-joblib
DEPENDS+=	${PYPKGPREFIX}-more-itertools-[0-9]*:../../devel/py-more-itertools
DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-scipy-[0-9]*:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-Levenshtein-[0-9]*:../../textproc/py-Levenshtein
DEPENDS+=	${PYPKGPREFIX}-jsonpickle-[0-9]*:../../textproc/py-jsonpickle
DEPENDS+=	${PYPKGPREFIX}-webcolors>=1.11:../../www/py-webcolors

# Many tests will fail because they depend on the score files that
# are part of the full music21 distribution.
TEST_DEPENDS+=	${PYPKGPREFIX}-guppy3-[0-9]*:../../devel/py-guppy3

USE_LANGUAGES=	# none

.include "options.mk"

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
