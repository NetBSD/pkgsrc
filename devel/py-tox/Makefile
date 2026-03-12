# $NetBSD: Makefile,v 1.65 2026/03/12 05:26:51 adam Exp $

DISTNAME=	tox-4.49.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/tox/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://tox.wiki/
COMMENT=	Virtualenv-based automation of test activities
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-vcs>=0.5:../../devel/py-hatch-vcs
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.29:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-cachetools>=7.0.3:../../devel/py-cachetools
DEPENDS+=	${PYPKGPREFIX}-colorama>=0.4.6:../../comms/py-colorama
DEPENDS+=	${PYPKGPREFIX}-filelock>=3.25:../../devel/py-filelock
DEPENDS+=	${PYPKGPREFIX}-packaging>=26:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-platformdirs>=4.9.4:../../misc/py-platformdirs
DEPENDS+=	${PYPKGPREFIX}-pluggy>=1.6:../../devel/py-pluggy
DEPENDS+=	${PYPKGPREFIX}-project-api>=1.10:../../devel/py-project-api
DEPENDS+=	${PYPKGPREFIX}-tomli_w>=1.2:../../textproc/py-tomli_w
DEPENDS+=	${PYPKGPREFIX}-virtualenv>=21.1:../../devel/py-virtualenv

# more unpackaged TEST_DEPENDS from pyproject.toml
# "detect-test-pollution>=1.2",
# "devpi-process>=1.1",
# "diff-cover>=10.2",
# "re-assert>=1.1",

TEST_DEPENDS+=	${PYPKGPREFIX}-build>=1.4:../../devel/py-build
TEST_DEPENDS+=	${PYPKGPREFIX}-covdefaults>=2.3:../../devel/py-covdefaults
TEST_DEPENDS+=	${PYPKGPREFIX}-distlib>=0.4:../../devel/py-distlib
TEST_DEPENDS+=	${PYPKGPREFIX}-flaky>=3.8.1:../../devel/py-flaky
TEST_DEPENDS+=	${PYPKGPREFIX}-psutil>=7.1:../../sysutils/py-psutil
TEST_DEPENDS+=	${PYPKGPREFIX}-setuptools>=80.10.2:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=7:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock>=3.15.1:../../devel/py-test-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=3.8:../../devel/py-test-xdist
TEST_DEPENDS+=	${PYPKGPREFIX}-time-machine>=3.2:../../time/py-time-machine
TEST_DEPENDS+=	${PYPKGPREFIX}-wheel>=0.46.3:../../devel/py-wheel

USE_LANGUAGES=	# none

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 311
DEPENDS+=	${PYPKGPREFIX}-tomli>=2.4:../../textproc/py-tomli
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.15:../../devel/py-typing-extensions
.endif

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} tox tox-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
