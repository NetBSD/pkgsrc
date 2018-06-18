# $NetBSD: Makefile,v 1.13 2018/06/18 07:15:17 adam Exp $

DISTNAME=	celery-4.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/celery/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.celeryproject.org/
COMMENT=	Asynchronous task/job queue based on distributed message passing
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-billiard>=3.5.0.2:../../parallel/py-billiard
DEPENDS+=	${PYPKGPREFIX}-kombu>=4.2.0:../../net/py-kombu
DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz
TEST_DEPENDS+=	${PYPKGPREFIX}-case>=1.3.1:../../devel/py-case
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=3.0:../../devel/py-test

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/celery \
		${DESTDIR}${PREFIX}/bin/celery${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
