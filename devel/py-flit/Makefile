# $NetBSD: Makefile,v 1.2 2020/12/05 03:22:34 riastradh Exp $

PKGNAME=	${PYPKGPREFIX}-${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://flit.readthedocs.io/
COMMENT=	Python and PyPI packaging tool
LICENSE=	modified-bsd

.include "Makefile.common"

DEPENDS+=	${PYPKGPREFIX}-docutils>=0:../../textproc/py-docutils
DEPENDS+=	${PYPKGPREFIX}-flit_core-${PKGVERSION_NOREV}:../../devel/py-flit_core
DEPENDS+=	${PYPKGPREFIX}-pytoml>=0:../../textproc/py-pytoml
DEPENDS+=	${PYPKGPREFIX}-requests>=0:../../devel/py-requests

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core-${PKGVERSION_NOREV}:../../devel/py-flit_core
TOOL_DEPENDS+=	${PYPKGPREFIX}-pep517>=0:../../devel/py-pep517
TOOL_DEPENDS+=	${PYPKGPREFIX}-pip>=0:../../devel/py-pip

TEST_DEPENDS+=	${PYPKGPREFIX}-responses>=0:../../net/py-responses
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=0:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-testpath>=0:../../devel/py-testpath

USE_LANGUAGES=	# none

MAKE_ENV+=	PIP_DISABLE_PIP_VERSION_CHECK=1
MAKE_ENV+=	PIP_ISOLATED=1
MAKE_ENV+=	PIP_NO_CACHE_DIR=1
MAKE_ENV+=	PIP_NO_DEPS=1
MAKE_ENV+=	PIP_NO_INDEX=1
MAKE_ENV+=	PIP_PREFIX=${PREFIX:Q}
MAKE_ENV+=	PIP_PROXY=0.0.0.0:0
MAKE_ENV+=	PIP_ROOT=${DESTDIR:Q}

do-build:
	${RUN} \
	cd ${WRKSRC} && \
	${SETENV} ${MAKE_ENV} \
	${PYTHONBIN} -c \
		'from flit_core.buildapi import build_wheel; build_wheel(".")'

do-install:
	${RUN} \
	cd ${WRKSRC} && \
	${SETENV} ${MAKE_ENV} ${PYTHONBIN} -m pip install -I \
		--no-warn-script-location \
		./flit-${GITHUB_TAG}-py3-none-any.whl
	${RUN} \
	cd ${DESTDIR:Q}${PREFIX:Q}/bin && \
	${MV} -f flit flit${PYVERSSUFFIX}

do-test:
	${RUN} \
	cd ${WRKSRC} && \
	${SETENV} ${TEST_ENV} ${PYTHONBIN} -m pytest

PY_PATCHPLIST=	yes
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
