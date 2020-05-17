# $NetBSD: Makefile,v 1.18 2020/05/17 19:36:41 adam Exp $

DISTNAME=	celery-4.4.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/celery/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.celeryproject.org/
COMMENT=	Asynchronous task/job queue based on distributed message passing
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-billiard>=3.6.3.0:../../parallel/py-billiard
DEPENDS+=	${PYPKGPREFIX}-kombu>=4.6.8:../../net/py-kombu
DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-vine>=1.3.0:../../devel/py-vine
TEST_DEPENDS+=	${PYPKGPREFIX}-case>=1.3.1:../../devel/py-case
TEST_DEPENDS+=	${PYPKGPREFIX}-mongo-[0-9]*:../../databases/py-mongo

PYTHON_VERSIONED_DEPENDENCIES=	test:test

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} celery celery-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
