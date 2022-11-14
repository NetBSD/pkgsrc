# $NetBSD: Makefile,v 1.16 2022/11/14 15:11:59 wiz Exp $

DISTNAME=	pygal-3.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pygal/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.pygal.org/
COMMENT=	Python SVG graph plotting library
LICENSE=	gnu-lgpl-v3

DEPENDS+=	${PYPKGPREFIX}-cairosvg-[0-9]*:../../converters/py-cairosvg
DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml
TEST_DEPENDS+=	${PYPKGPREFIX}-flask-[0-9]*:../../www/py-flask
TEST_DEPENDS+=	${PYPKGPREFIX}-pyquery-[0-9]*:../../textproc/py-pyquery
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-flake8-[0-9]*:../../devel/py-test-flake8
TEST_DEPENDS+=	${PYPKGPREFIX}-test-isort-[0-9]*:../../devel/py-test-isort
TOOL_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner

USE_LANGUAGES=	# none

USE_PKG_RESOURCES=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} pygal_gen.py pygal_gen${PYVERSSUFFIX}.py || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
