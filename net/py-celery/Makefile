# $NetBSD: Makefile,v 1.11 2017/08/25 20:03:39 joerg Exp $

DISTNAME=	celery-4.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/celery/}

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://www.celeryproject.org/
COMMENT=	Asynchronous task/job queue based on distributed message passing
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-billiard>=3.5.0.2:../../parallel/py-billiard
DEPENDS+=	${PYPKGPREFIX}-kombu>=4.1.0:../../net/py-kombu
DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz

USE_LANGUAGES=	c

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/celery \
		${DESTDIR}${PREFIX}/bin/celery${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
