# $NetBSD: Makefile,v 1.18 2024/08/10 15:46:27 wiz Exp $

DISTNAME=	pygal-3.0.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pygal/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.pygal.org/
COMMENT=	Python SVG graph plotting library
LICENSE=	gnu-lgpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-importlib-metadata-[0-9]*:../../devel/py-importlib-metadata
# png
DEPENDS+=	${PYPKGPREFIX}-cairosvg-[0-9]*:../../converters/py-cairosvg
# lxml
DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml
TEST_DEPENDS+=	${PYPKGPREFIX}-flask-[0-9]*:../../www/py-flask
TEST_DEPENDS+=	${PYPKGPREFIX}-pyquery-[0-9]*:../../textproc/py-pyquery
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-flake8-[0-9]*:../../devel/py-test-flake8
TEST_DEPENDS+=	${PYPKGPREFIX}-test-isort-[0-9]*:../../devel/py-test-isort

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

# as of 3.0.4
# 4414 passed, 8710 warnings

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} pygal_gen.py pygal_gen${PYVERSSUFFIX}.py || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
