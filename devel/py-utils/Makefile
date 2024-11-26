# $NetBSD: Makefile,v 1.16 2024/11/26 12:04:43 adam Exp $

DISTNAME=	python_utils-3.9.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python_//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-utils/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/WoLpH/python-utils
COMMENT=	Some convenient utilities not included with standard Python
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>3.10.0.2:../../devel/py-typing-extensions
TEST_DEPENDS+=	${PYPKGPREFIX}-loguru-[0-9]*:../../sysutils/py-loguru
TEST_DEPENDS+=	${PYPKGPREFIX}-test-asyncio-[0-9]*:../../devel/py-test-asyncio
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mypy-[0-9]*:../../devel/py-test-mypy
TEST_DEPENDS+=	${PYPKGPREFIX}-types-setuptools-[0-9]*:../../devel/py-types-setuptools

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
