# $NetBSD: Makefile,v 1.13 2026/05/24 05:45:29 adam Exp $

DISTNAME=	pytest_codspeed-5.0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//:S/_/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-codspeed/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/CodSpeedHQ/pytest-codspeed
COMMENT=	Pytest plugin to create CodSpeed benchmarks
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-rich>=13.8.1:../../comms/py-rich
DEPENDS+=	${PYPKGPREFIX}-test>=3.8:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=4.0.0:../../devel/py-test-cov

USE_LANGUAGES=	# none

MAKE_ENV+=	PYTEST_CODSPEED_SKIP_EXTENSION_BUILD=1

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
