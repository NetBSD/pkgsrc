# $NetBSD: Makefile,v 1.2 2026/05/24 12:46:43 wiz Exp $

DISTNAME=	influxdb-5.3.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/influxdb/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/influxdb/influxdb-python
COMMENT=	InfluxDB 1.x client for Python
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-msgpack-[0-9]*:../../devel/py-msgpack
DEPENDS+=	${PYPKGPREFIX}-requests>=2.17.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-six>=1.10.0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.6.0:../../time/py-dateutil
TEST_DEPENDS+=	${PYPKGPREFIX}-mock>=0:../../devel/py-mock
#TEST_DEPENDS+=	${PYPKGPREFIX}-nose>=0:../../devel/py-nose
TEST_DEPENDS+=	${PYPKGPREFIX}-requests-mock>=0:../../devel/py-requests-mock

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
