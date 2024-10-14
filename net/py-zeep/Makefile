# $NetBSD: Makefile,v 1.18 2024/10/14 09:51:56 adam Exp $

DISTNAME=	zeep-4.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=z/zeep/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.python-zeep.org/
COMMENT=	Fast and modern Python SOAP client
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-attrs>=17.2.0:../../devel/py-attrs
DEPENDS+=	${PYPKGPREFIX}-isodate>=0.5.4:../../time/py-isodate
DEPENDS+=	${PYPKGPREFIX}-lxml>=4.6.0:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-platformdirs>=1.4.0:../../misc/py-platformdirs
DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-requests>=2.7.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-requests-file>=1.5.1:../../devel/py-requests-file
DEPENDS+=	${PYPKGPREFIX}-requests-toolbelt>=0.7.1:../../devel/py-requests-toolbelt
TEST_DEPENDS+=	${PYPKGPREFIX}-freezegun>=0.3.15:../../devel/py-freezegun
TEST_DEPENDS+=	${PYPKGPREFIX}-pretend>=1.0.9:../../devel/py-pretend
TEST_DEPENDS+=	${PYPKGPREFIX}-requests-mock>=0.7.0:../../devel/py-requests-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=6.2.5:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-asyncio-[0-9]*:../../devel/py-test-asyncio
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=2.8.1:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-httpx-[0-9]*:../../www/py-test-httpx

USE_LANGUAGES=	# none

# 471 passed, 18 skipped, 32 warnings

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
