# $NetBSD: Makefile,v 1.52 2024/09/10 07:43:20 adam Exp $

DISTNAME=	tox-4.18.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/tox/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://tox.wiki/
COMMENT=	Virtualenv-based automation of test activities
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.25:../../devel/py-hatchling
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-vcs>=0.4:../../devel/py-hatch-vcs
DEPENDS+=	${PYPKGPREFIX}-cachetools>=5.3.3:../../devel/py-cachetools
DEPENDS+=	${PYPKGPREFIX}-chardet>=5.2:../../converters/py-chardet
DEPENDS+=	${PYPKGPREFIX}-colorama>=0.4.6:../../comms/py-colorama
DEPENDS+=	${PYPKGPREFIX}-filelock>=3.15.4:../../devel/py-filelock
DEPENDS+=	${PYPKGPREFIX}-packaging>=24.1:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-platformdirs>=4.2.2:../../misc/py-platformdirs
DEPENDS+=	${PYPKGPREFIX}-pluggy>=1.5:../../devel/py-pluggy
DEPENDS+=	${PYPKGPREFIX}-project-api>=1.7.1:../../devel/py-project-api
DEPENDS+=	${PYPKGPREFIX}-virtualenv>=20.26.3:../../devel/py-virtualenv

# more unpackaged TEST_DEPENDS from pyproject.toml
# "detect-test-pollution>=1.1.1",
# "devpi-process>=0.3.1",
# "diff-cover>=7.6",
# "re-assert>=1.1",

TEST_DEPENDS+=	${PYPKGPREFIX}-build>=1.2.1:../../devel/py-build
TEST_DEPENDS+=	${PYPKGPREFIX}-covdefaults>=2.3:../../devel/py-covdefaults
TEST_DEPENDS+=	${PYPKGPREFIX}-distlib>=0.3.8:../../devel/py-distlib
TEST_DEPENDS+=	${PYPKGPREFIX}-flaky>=3.8.1:../../devel/py-flaky
TEST_DEPENDS+=	${PYPKGPREFIX}-psutil>=6:../../sysutils/py-psutil
TEST_DEPENDS+=	${PYPKGPREFIX}-setuptools>=70.2:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=5:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock>=3.14:../../devel/py-test-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=3.6.1:../../devel/py-test-xdist
TEST_DEPENDS+=	${PYPKGPREFIX}-time-machine>=2.14.2:../../time/py-time-machine
TEST_DEPENDS+=	${PYPKGPREFIX}-wheel>=0.43:../../devel/py-wheel

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 311
DEPENDS+=	${PYPKGPREFIX}-tomli>=2.0.1:../../textproc/py-tomli
.endif

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} tox tox-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
