# $NetBSD: Makefile,v 1.1 2026/05/22 16:54:21 ryoon Exp $

DISTNAME=	influxdb-5.3.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/influxdb/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/influxdb/influxdb-python
COMMENT=	InfluxDB 1.x client for Python
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-msgpack-[0-9]*:../../devel/py-msgpack
DEPENDS+=	${PYPKGPREFIX}-requests>=2.17.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-six>=1.10.0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.6.0:../../time/py-dateutil

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
