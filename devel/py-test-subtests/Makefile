# $NetBSD: Makefile,v 1.3 2022/11/21 20:21:57 adam Exp $

DISTNAME=	pytest-subtests-0.9.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-subtests/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pytest-dev/pytest-subtests
COMMENT=	Unittest subTest() support and subtests fixture
LICENSE=	mit

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-test>=7.0:../../devel/py-test

PYTHON_VERSIONS_INCOMPATIBLE=	27

#TEST_ENV+=	PYTHONPATH=${WRKSRC}/build/lib
# needs to be installed for testing
do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
