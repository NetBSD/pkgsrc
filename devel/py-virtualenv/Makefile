# $NetBSD: Makefile,v 1.57 2022/07/07 11:49:50 adam Exp $

DISTNAME=	virtualenv-20.15.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=v/virtualenv/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://virtualenv.pypa.io/
COMMENT=	Virtual Python Environment builder
LICENSE=	mit

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-distlib>=0.3.1:../../devel/py-distlib
DEPENDS+=	${PYPKGPREFIX}-filelock>=3.2:../../devel/py-filelock
DEPENDS+=	${PYPKGPREFIX}-platformdirs>=2:../../misc/py-platformdirs
DEPENDS+=	${PYPKGPREFIX}-six>=1.9.0:../../lang/py-six
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage>=4:../../devel/py-coverage
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage-enable-subprocess>=1:../../devel/py-coverage-enable-subprocess
TEST_DEPENDS+=	${PYPKGPREFIX}-flaky>=3:../../devel/py-flaky
TEST_DEPENDS+=	${PYPKGPREFIX}-packaging>=20.0:../../devel/py-packaging
TEST_DEPENDS+=	${PYPKGPREFIX}-pip-[0-9]*:../../devel/py-pip
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=4:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-env>=0.6.2:../../devel/py-test-env
TEST_DEPENDS+=	${PYPKGPREFIX}-test-freezegun>=0.4.1:../../devel/py-test-freezegun
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock>=2:../../devel/py-test-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-randomly>=1:../../devel/py-test-randomly
TEST_DEPENDS+=	${PYPKGPREFIX}-test-timeout>=1:../../devel/py-test-timeout

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-filelock, py-platformdirs, py-packaging

.include "../../lang/python/pyversion.mk"

.if ${_PYTHON_VERSION} == 37
DEPENDS+=	${PYPKGPREFIX}-importlib-metadata-[0-9]*:../../devel/py-importlib-metadata
.endif

USE_PKG_RESOURCES=	yes

USE_LANGUAGES=	c # for tests

REPLACE_PYTHON=	virtualenv.py

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} virtualenv virtualenv-${PYVERSSUFFIX} || ${TRUE}

# needs 'make install' and USE_LANGUAGES=c
do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
