# $NetBSD: Makefile,v 1.8 2025/04/15 05:38:03 adam Exp $

DISTNAME=	flower-2.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/flower/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mher/flower
COMMENT=	Real-time monitor and web admin for Celery task queue
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-celery>=5.0.5:../../net/py-celery
DEPENDS+=	${PYPKGPREFIX}-tornado>=5.0.0:../../www/py-tornado
DEPENDS+=	${PYPKGPREFIX}-prometheus_client>=0.8.0:../../net/py-prometheus_client
DEPENDS+=	${PYPKGPREFIX}-humanize-[0-9]*:../../textproc/py-humanize
DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
