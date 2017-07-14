# $NetBSD: Makefile,v 1.13 2017/07/14 11:39:32 adam Exp $

DISTNAME=	eventlib-0.1.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=e/eventlib/}

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://travis-ci.org/Yipit/eventlib/
COMMENT=	Asynchronous event tracking app for Django
LICENSE=	gnu-lgpl-v3

DEPENDS+=	${PYPKGPREFIX}-ejson>=0.1.3:../../textproc/py-ejson
DEPENDS+=	${PYPKGPREFIX}-logan>=0.5.0:../../devel/py-logan
DEPENDS+=	${PYPKGPREFIX}-celery>=3.0.9:../../net/py-celery
DEPENDS+=	${PYPKGPREFIX}-redis>=2.7.1:../../databases/py-redis-py
DEPENDS+=	${PYPKGPREFIX}-django>=1.4.1:../../www/py-django

USE_LANGUAGES=	# none

PY_PATCHPLIST=	yes
PYTHON_VERSIONS_INCOMPATIBLE+=	34 35 36	# not yet ported as of 0.1.5

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/eventlib \
		${DESTDIR}${PREFIX}/bin/eventlib${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
