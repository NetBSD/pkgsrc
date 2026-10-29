# $NetBSD: Makefile,v 1.14 2026/10/29 16:38:13 adam Exp $

DISTNAME=	gcovr-8.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/gcovr/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/gcovr/gcovr
COMMENT=	Generate GCC code coverage reports
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-fancy-pypi-readme>=25.1.0:../../devel/py-hatch-fancy-pypi-readme
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-vcs>=0.5.0:../../devel/py-hatch-vcs
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.27.0:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-colorlog>=0:../../devel/py-colorlog
DEPENDS+=	${PYPKGPREFIX}-jinja2>=0:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-lxml>=0:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-pygments>=2.13.0:../../textproc/py-pygments
TEST_DEPENDS+=	${PYPKGPREFIX}-test-timeout>0:../../devel/py-test-timeout

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	gcovr

PYTHON_VERSIONS_INCOMPATIBLE=	311

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
