# $NetBSD: Makefile,v 1.62 2026/01/09 12:50:45 adam Exp $

DISTNAME=	tox-4.34.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/tox/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://tox.wiki/
COMMENT=	Virtualenv-based automation of test activities
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-vcs>=0.5:../../devel/py-hatch-vcs
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.28:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-cachetools>=6.2.4:../../devel/py-cachetools
DEPENDS+=	${PYPKGPREFIX}-chardet>=5.2:../../converters/py-chardet
DEPENDS+=	${PYPKGPREFIX}-colorama>=0.4.6:../../comms/py-colorama
DEPENDS+=	${PYPKGPREFIX}-filelock>=3.20.2:../../devel/py-filelock
DEPENDS+=	${PYPKGPREFIX}-packaging>=25:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-platformdirs>=4.5.1:../../misc/py-platformdirs
DEPENDS+=	${PYPKGPREFIX}-pluggy>=1.6:../../devel/py-pluggy
DEPENDS+=	${PYPKGPREFIX}-project-api>=1.10:../../devel/py-project-api
DEPENDS+=	${PYPKGPREFIX}-virtualenv>=20.35.4:../../devel/py-virtualenv

# more unpackaged TEST_DEPENDS from pyproject.toml
# "detect-test-pollution>=1.2",
# "devpi-process>=1.0.2",
# "diff-cover>=9.2",
# "re-assert>=1.1",

TEST_DEPENDS+=	${PYPKGPREFIX}-build>=1.3:../../devel/py-build
TEST_DEPENDS+=	${PYPKGPREFIX}-covdefaults>=2.3:../../devel/py-covdefaults
TEST_DEPENDS+=	${PYPKGPREFIX}-distlib>=0.4:../../devel/py-distlib
TEST_DEPENDS+=	${PYPKGPREFIX}-flaky>=3.8.1:../../devel/py-flaky
TEST_DEPENDS+=	${PYPKGPREFIX}-psutil>=7.1:../../sysutils/py-psutil
TEST_DEPENDS+=	${PYPKGPREFIX}-setuptools>=80.9:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=7:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock>=3.14:../../devel/py-test-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=3.6.1:../../devel/py-test-xdist
TEST_DEPENDS+=	${PYPKGPREFIX}-time-machine>=2.15:../../time/py-time-machine
TEST_DEPENDS+=	${PYPKGPREFIX}-wheel>=0.45.1:../../devel/py-wheel

USE_LANGUAGES=	# none

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 311
DEPENDS+=	${PYPKGPREFIX}-tomli>=2.3:../../textproc/py-tomli
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.15:../../devel/py-typing-extensions
.endif

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} tox tox-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
