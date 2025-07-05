# $NetBSD: Makefile,v 1.26 2025/07/05 11:44:09 wiz Exp $

DISTNAME=	poetry-2.1.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/poetry/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://python-poetry.org/
COMMENT=	Python dependency management and packaging made easy
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-build>=1.2.1:../../devel/py-build
DEPENDS+=	${PYPKGPREFIX}-cachecontrol>=0.14.0:../../devel/py-cachecontrol
DEPENDS+=	${PYPKGPREFIX}-cleo>=2.1.0:../../comms/py-cleo
DEPENDS+=	${PYPKGPREFIX}-crashtest>=0.4.1:../../misc/py-crashtest
DEPENDS+=	${PYPKGPREFIX}-dulwich>=0.22.6:../../devel/py-dulwich
DEPENDS+=	${PYPKGPREFIX}-fastjsonschema>=2.18.0:../../textproc/py-fastjsonschema
DEPENDS+=	${PYPKGPREFIX}-findpython>=0.6.2:../../lang/py-findpython
DEPENDS+=	${PYPKGPREFIX}-installer>=0.7.0:../../misc/py-installer
DEPENDS+=	${PYPKGPREFIX}-keyring>=25.1.0:../../security/py-keyring
DEPENDS+=	${PYPKGPREFIX}-packaging>=24.0:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-pbs-installer>=2025.1.6:../../misc/py-pbs-installer
DEPENDS+=	${PYPKGPREFIX}-pkginfo>=1.12:../../devel/py-pkginfo
DEPENDS+=	${PYPKGPREFIX}-platformdirs>=3.0.0:../../misc/py-platformdirs
DEPENDS+=	${PYPKGPREFIX}-poetry-core>=2.1.2:../../devel/py-poetry-core
DEPENDS+=	${PYPKGPREFIX}-pyproject_hooks>=1.0.0:../../devel/py-pyproject_hooks
DEPENDS+=	${PYPKGPREFIX}-requests>=2.26:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-requests-toolbelt>=1.0.0:../../devel/py-requests-toolbelt
DEPENDS+=	${PYPKGPREFIX}-shellingham>=1.5:../../misc/py-shellingham
DEPENDS+=	${PYPKGPREFIX}-tomlkit>=0.11.4:../../textproc/py-tomlkit
DEPENDS+=	${PYPKGPREFIX}-trove-classifiers>=2022.5.19:../../misc/py-trove-classifiers
DEPENDS+=	${PYPKGPREFIX}-virtualenv>=20.26.6:../../devel/py-virtualenv
TEST_DEPENDS+=	${PYPKGPREFIX}-deepdiff>=6.3:../../textproc/py-deepdiff
TEST_DEPENDS+=	${PYPKGPREFIX}-httpretty>=1.0:../../www/py-httpretty
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=4.0:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock>=3.9:../../devel/py-test-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-randomly>=3.12:../../devel/py-test-randomly
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=3.1:../../devel/py-test-xdist

# for tests
USE_LANGUAGES=	c

PYTHON_VERSIONS_INCOMPATIBLE=	39 310

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Darwin"
DEPENDS+=	${PYPKGPREFIX}-xattr>=1.0.0:../../sysutils/py-xattr
.endif

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} poetry poetry-${PYVERSSUFFIX} || ${TRUE}

# some tests use 'python'
.include "../../lang/python/tool.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
