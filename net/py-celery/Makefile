# $NetBSD: Makefile,v 1.6 2016/06/08 17:43:37 wiz Exp $
#

DISTNAME=	celery-3.1.16
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/celery/}

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://www.celeryproject.org/
COMMENT=	Asynchronous task/job queue based on distributed message passing
LICENSE=	modified-bsd AND cc-by-nc-sa-v3.0-license

DEPENDS+=	${PYPKGPREFIX}-anyjson-[0-9]*:../../textproc/py-anyjson
DEPENDS+=	${PYPKGPREFIX}-billiard>=3.3.0.18:../../parallel/py-billiard
DEPENDS+=	${PYPKGPREFIX}-kombu>=3.0.22:../../net/py-kombu
DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz

USE_LANGUAGES=	c

PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/celery \
		${DESTDIR}${PREFIX}/bin/celery${PYVERSSUFFIX}
	${MV} ${DESTDIR}${PREFIX}/bin/celerybeat \
		${DESTDIR}${PREFIX}/bin/celerybeat${PYVERSSUFFIX}
	${MV} ${DESTDIR}${PREFIX}/bin/celeryd \
		${DESTDIR}${PREFIX}/bin/celeryd${PYVERSSUFFIX}
	${MV} ${DESTDIR}${PREFIX}/bin/celeryd-multi \
		${DESTDIR}${PREFIX}/bin/celeryd-multi${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
