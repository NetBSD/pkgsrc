# $NetBSD: Makefile,v 1.32 2022/08/24 10:03:24 wiz Exp $

DISTNAME=	pytest-xdist-2.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-xdist/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pytest-dev/pytest-xdist
COMMENT=	Plugin for distributed testing and loop-on-failing modes
LICENSE=	mit

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
BUILD_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-execnet>=1.1:../../devel/py-execnet
DEPENDS+=	${PYPKGPREFIX}-test>=6.2:../../devel/py-test
DEPENDS+=	${PYPKGPREFIX}-test-forked>=0:../../devel/py-test-forked
TEST_DEPENDS+=	${PYPKGPREFIX}-filelock-[0-9]*:../../devel/py-filelock

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_LANGUAGES=	# none

# needs to be installed for testing, this setting is not enough
TEST_ENV+=	PYTHONPATH=${WRKSRC}/build/lib
do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} testing

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
