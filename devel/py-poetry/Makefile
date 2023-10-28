# $NetBSD: Makefile,v 1.14 2023/10/28 19:57:05 wiz Exp $

DISTNAME=	poetry-1.6.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/poetry/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://python-poetry.org/
COMMENT=	Python dependency management and packaging made easy
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-build>=0.10.0:../../devel/py-build
DEPENDS+=	${PYPKGPREFIX}-cachecontrol>=0.13.0:../../devel/py-cachecontrol
DEPENDS+=	${PYPKGPREFIX}-cleo>=2.0.0:../../comms/py-cleo
DEPENDS+=	${PYPKGPREFIX}-crashtest>=0.4.1:../../misc/py-crashtest
DEPENDS+=	${PYPKGPREFIX}-dulwich>=0.21.2:../../devel/py-dulwich
DEPENDS+=	${PYPKGPREFIX}-installer>=0.7.0:../../misc/py-installer
DEPENDS+=	${PYPKGPREFIX}-jsonschema>=4.10.0:../../textproc/py-jsonschema
DEPENDS+=	${PYPKGPREFIX}-keyring>=24.0.0:../../security/py-keyring
DEPENDS+=	${PYPKGPREFIX}-packaging>=20.4:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-pexpect>=4.7.0:../../devel/py-pexpect
DEPENDS+=	${PYPKGPREFIX}-pkginfo>=1.9.4:../../devel/py-pkginfo
DEPENDS+=	${PYPKGPREFIX}-platformdirs>=3.0.0:../../misc/py-platformdirs
DEPENDS+=	${PYPKGPREFIX}-poetry-core>=1.7.0:../../devel/py-poetry-core
DEPENDS+=	${PYPKGPREFIX}-poetry-plugin-export>=1.5.0:../../devel/py-poetry-plugin-export
DEPENDS+=	${PYPKGPREFIX}-pyproject_hooks>=1.0.0:../../devel/py-pyproject_hooks
DEPENDS+=	${PYPKGPREFIX}-requests>=2.26:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-requests-toolbelt>=0.9.1:../../devel/py-requests-toolbelt
DEPENDS+=	${PYPKGPREFIX}-shellingham>=1.5:../../misc/py-shellingham
DEPENDS+=	${PYPKGPREFIX}-tomlkit>=0.11.4:../../textproc/py-tomlkit
DEPENDS+=	${PYPKGPREFIX}-trove-classifiers>=2022.5.19:../../misc/py-trove-classifiers
DEPENDS+=	${PYPKGPREFIX}-virtualenv>=20.4.7:../../devel/py-virtualenv
TEST_DEPENDS+=	${PYPKGPREFIX}-deepdiff>=6.3:../../textproc/py-deepdiff
TEST_DEPENDS+=	${PYPKGPREFIX}-httpretty>=1.0:../../www/py-httpretty
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=7.1:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=4.0:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock>=3.9:../../devel/py-test-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-randomly>=3.12:../../devel/py-test-randomly
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=3.1:../../devel/py-test-xdist

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Darwin"
DEPENDS+=	${PYPKGPREFIX}-xattr>=0.10.1:../../sysutils/py-xattr
.endif

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 310
DEPENDS+=	${PYPKGPREFIX}-importlib-metadata>=4.4:../../devel/py-importlib-metadata
.endif
.if ${PYTHON_VERSION} < 311
DEPENDS+=	${PYPKGPREFIX}-tomli>=2.0.1:../../textproc/py-tomli
.endif

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} poetry poetry-${PYVERSSUFFIX} || ${TRUE}

# needs 'make install'
# as of 1.5.1:
# 1 failed, 1374 passed, 6 skipped
do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests

# some tests use 'python'
.include "../../lang/python/tool.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
