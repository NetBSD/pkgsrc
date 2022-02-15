# $NetBSD: Makefile,v 1.5 2022/02/15 16:38:15 wiz Exp $

DISTNAME=	flower-1.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/flower/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mher/flower
COMMENT=	Real-time monitor and web admin for Celery task queue
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-celery>=5.0.5:../../net/py-celery
DEPENDS+=	${PYPKGPREFIX}-tornado>=5.0.0:../../www/py-tornado
DEPENDS+=	${PYPKGPREFIX}-prometheus_client>=0.8.0:../../net/py-prometheus_client
DEPENDS+=	${PYPKGPREFIX}-humanize-[0-9]*:../../textproc/py-humanize
DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

# as of 1.0.0
# 119 passed, 1 skipped, 752 warnings
do-test:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
