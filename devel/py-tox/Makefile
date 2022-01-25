# $NetBSD: Makefile,v 1.26 2022/01/25 09:05:11 wiz Exp $

DISTNAME=	tox-3.20.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/tox/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://tox.readthedocs.io/
COMMENT=	Virtualenv-based automation of test activities
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-filelock>=3.0.0:../../devel/py-filelock
DEPENDS+=	${PYPKGPREFIX}-pluggy>=0.12.0:../../devel/py-pluggy
DEPENDS+=	${PYPKGPREFIX}-py>=1.4.17:../../devel/py-py
DEPENDS+=	${PYPKGPREFIX}-six>=1.14.0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-toml>=0.9.4:../../textproc/py-toml
DEPENDS+=	${PYPKGPREFIX}-virtualenv>=16.0.0:../../devel/py-virtualenv
TEST_DEPENDS+=	${PYPKGPREFIX}-flaky>=3.4.0:../../devel/py-flaky
TEST_DEPENDS+=	${PYPKGPREFIX}-freezegun>=0.3.11:../../devel/py-freezegun
TEST_DEPENDS+=	${PYPKGPREFIX}-pathlib2>=2.3.3:../../devel/py-pathlib2
TEST_DEPENDS+=	${PYPKGPREFIX}-psutil>=5.6.1:../../sysutils/py-psutil
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=2.5.1:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock>=1.10.0:../../devel/py-test-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-randomly>=1.0.0:../../devel/py-test-randomly
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=1.22.2:../../devel/py-test-xdist

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} < 38
PYTHON_VERSIONED_DEPENDENCIES+=	importlib-metadata
.endif

PYTHON_VERSIONED_DEPENDENCIES+=	packaging
PYTHON_VERSIONED_DEPENDENCIES+=	test:test
PYTHON_VERSIONED_DEPENDENCIES+=	setuptools_scm:build

USE_PKG_RESOURCES=	yes

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} tox tox-${PYVERSSUFFIX} && \
	${MV} tox-quickstart tox-quickstart-${PYVERSSUFFIX} || ${TRUE}

do-test:
	cd ${WRKSRC} && pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
