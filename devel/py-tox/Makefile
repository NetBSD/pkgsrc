# $NetBSD: Makefile,v 1.35 2023/08/24 20:33:39 wiz Exp $

DISTNAME=	tox-4.10.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/tox/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://tox.wiki/
COMMENT=	Virtualenv-based automation of test activities
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.17.1:../../devel/py-hatchling
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-vcs>=0.3:../../devel/py-hatch-vcs
DEPENDS+=	${PYPKGPREFIX}-cachetools>=5.3.1:../../devel/py-cachetools
DEPENDS+=	${PYPKGPREFIX}-chardet>=5.1:../../converters/py-chardet
DEPENDS+=	${PYPKGPREFIX}-colorama>=0.4.6:../../comms/py-colorama
DEPENDS+=	${PYPKGPREFIX}-filelock>=3.12.2:../../devel/py-filelock
DEPENDS+=	${PYPKGPREFIX}-packaging>=23.1:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-platformdirs>=3.8:../../misc/py-platformdirs
DEPENDS+=	${PYPKGPREFIX}-pluggy>=1.2:../../devel/py-pluggy
DEPENDS+=	${PYPKGPREFIX}-project-api>=1.5.2:../../devel/py-project-api
DEPENDS+=	${PYPKGPREFIX}-virtualenv>=20.23.1:../../devel/py-virtualenv

# more unpackaged TEST_DEPENDS from pyproject.toml
# "build[virtualenv]>=0.10",
# "covdefaults>=2.3",
# "devpi-process>=0.3.1",
# "diff-cover>=7.6",
# "re-assert>=1.1",

TEST_DEPENDS+=	${PYPKGPREFIX}-distlib>=0.3.6:../../devel/py-distlib
TEST_DEPENDS+=	${PYPKGPREFIX}-flaky>=3.7.0:../../devel/py-flaky
TEST_DEPENDS+=	${PYPKGPREFIX}-psutil>=5.9.5:../../sysutils/py-psutil
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=7.4:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=4.1:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock>=3.11.1:../../devel/py-test-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=3.3.1:../../devel/py-test-xdist
TEST_DEPENDS+=	${PYPKGPREFIX}-time-machine>=2.10:../../time/py-time-machine
TEST_DEPENDS+=	${PYPKGPREFIX}-wheel>=0.40:../../devel/py-wheel

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 311
DEPENDS+=	${PYPKGPREFIX}-tomli>=2.0.1:../../textproc/py-tomli
.endif

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} tox tox-${PYVERSSUFFIX} || ${TRUE}

# needs to be installed first
do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
