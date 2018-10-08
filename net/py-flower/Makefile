# $NetBSD: Makefile,v 1.1 2018/10/08 14:48:46 adam Exp $

DISTNAME=	flower-0.9.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/flower/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mher/flower
COMMENT=	Real-time monitor and web admin for Celery task queue
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-babel>=1.0:../../devel/py-babel
DEPENDS+=	${PYPKGPREFIX}-celery>=3.1.0:../../net/py-celery
DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-tornado>=4.2.0:../../www/py-tornado
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} == 27
DEPENDS+=	${PYPKGPREFIX}-futures-[0-9]*:../../devel/py-futures
.endif

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
		${MV} flower flower-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
