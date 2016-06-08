# $NetBSD: Makefile,v 1.8 2016/06/08 17:43:37 wiz Exp $

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
DEPENDS+=	${PYPKGPREFIX}-redis-py>=2.7.1:../../databases/py-redis-py
DEPENDS+=	${PYPKGPREFIX}-django>=1.4.1:../../www/py-django

USE_LANGUAGES=	# none

PY_PATCHPLIST=	yes
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}
PYTHON_VERSIONS_INCOMPATIBLE+=	33 34 35	# not yet ported as of 0.1.5

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/eventlib \
		${DESTDIR}${PREFIX}/bin/eventlib${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
