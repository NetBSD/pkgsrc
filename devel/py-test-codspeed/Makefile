# $NetBSD: Makefile,v 1.3 2024/12/15 08:57:26 wiz Exp $

DISTNAME=	pytest_codspeed-3.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//:S/_/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-codspeed/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/CodSpeedHQ/pytest-codspeed
COMMENT=	Pytest plugin to create CodSpeed benchmarks
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-cffi>=1.17.1:../../devel/py-cffi
DEPENDS+=	${PYPKGPREFIX}-filelock>=3.12.2:../../devel/py-filelock
DEPENDS+=	${PYPKGPREFIX}-rich>=13.8.1:../../comms/py-rich
DEPENDS+=	${PYPKGPREFIX}-test>=3.8:../../devel/py-test

USE_LANGUAGES=	# none

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 310
DEPENDS+=	${PYPKGPREFIX}-importlib-metadata>=8.5.0:../../devel/py-importlib-metadata
.endif

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
