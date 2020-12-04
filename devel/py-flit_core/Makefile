# $NetBSD: Makefile,v 1.1 2020/12/04 23:29:33 riastradh Exp $

PKGNAME=	${PYPKGPREFIX}-${GITHUB_PROJECT}_core-${DISTNAME}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://flit.readthedocs.io/
COMMENT=	Python and PyPI packaging tool -- core library
LICENSE=	modified-bsd

.include "../../devel/py-flit/Makefile.common"

TOOL_DEPENDS+=	${PYPKGPREFIX}-pip>=0:../../devel/py-pip
TOOL_DEPENDS+=	${PYPKGPREFIX}-pytoml>=0:../../textproc/py-pytoml

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
	cd ${WRKSRC}/flit_core && \
	${SETENV} ${MAKE_ENV} ${PYTHONBIN} build_dists.py

do-install:
	${RUN} \
	cd ${WRKSRC}/flit_core/dist && \
	${SETENV} ${MAKE_ENV} pip${PYVERSSUFFIX} install \
		./flit_core-${GITHUB_TAG}-py3-none-any.whl

PY_PATCHPLIST=	yes
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
