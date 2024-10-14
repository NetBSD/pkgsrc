# $NetBSD: Makefile,v 1.53 2024/10/14 17:12:34 adam Exp $

DISTNAME=	tox-4.21.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/tox/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://tox.wiki/
COMMENT=	Virtualenv-based automation of test activities
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-vcs>=0.4:../../devel/py-hatch-vcs
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.25:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-cachetools>=5.5:../../devel/py-cachetools
DEPENDS+=	${PYPKGPREFIX}-chardet>=5.2:../../converters/py-chardet
DEPENDS+=	${PYPKGPREFIX}-colorama>=0.4.6:../../comms/py-colorama
DEPENDS+=	${PYPKGPREFIX}-filelock>=3.16.1:../../devel/py-filelock
DEPENDS+=	${PYPKGPREFIX}-packaging>=24.1:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-platformdirs>=4.3.6:../../misc/py-platformdirs
DEPENDS+=	${PYPKGPREFIX}-pluggy>=1.5:../../devel/py-pluggy
DEPENDS+=	${PYPKGPREFIX}-project-api>=1.8:../../devel/py-project-api
DEPENDS+=	${PYPKGPREFIX}-virtualenv>=20.26.6:../../devel/py-virtualenv

# more unpackaged TEST_DEPENDS from pyproject.toml
# "detect-test-pollution>=1.2",
# "devpi-process>=1.0.2",
# "diff-cover>=9.2",
# "re-assert>=1.1",

TEST_DEPENDS+=	${PYPKGPREFIX}-build>=1.2.2:../../devel/py-build
TEST_DEPENDS+=	${PYPKGPREFIX}-covdefaults>=2.3:../../devel/py-covdefaults
TEST_DEPENDS+=	${PYPKGPREFIX}-distlib>=0.3.8:../../devel/py-distlib
TEST_DEPENDS+=	${PYPKGPREFIX}-flaky>=3.8.1:../../devel/py-flaky
TEST_DEPENDS+=	${PYPKGPREFIX}-psutil>=6:../../sysutils/py-psutil
TEST_DEPENDS+=	${PYPKGPREFIX}-setuptools>=75.1:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=5:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock>=3.14:../../devel/py-test-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=3.6.1:../../devel/py-test-xdist
TEST_DEPENDS+=	${PYPKGPREFIX}-time-machine>=2.15:../../time/py-time-machine
TEST_DEPENDS+=	${PYPKGPREFIX}-wheel>=0.44:../../devel/py-wheel

USE_LANGUAGES=	# none

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 311
DEPENDS+=	${PYPKGPREFIX}-tomli>=2.0.1:../../textproc/py-tomli
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.12.2:../../devel/py-typing-extensions
.endif

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} tox tox-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
