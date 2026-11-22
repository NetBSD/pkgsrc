# $NetBSD: Makefile,v 1.37 2026/11/22 20:03:02 wiz Exp $

DISTNAME=	wcwidth-0.9.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=w/wcwidth/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/jquast/wcwidth
COMMENT=	Measures number of Terminal column cells of wide-character codes
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=84.2:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=0:../../devel/py-test-cov

# Follow upstream (see tox.ini) and provide the extension in-place for testing.
do-test:
	cd ${WRKSRC} && \
		${SETENV} ${TEST_ENV} ${PYTHONBIN} setup.py build_ext --inplace
	cd ${WRKSRC} && \
		${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
