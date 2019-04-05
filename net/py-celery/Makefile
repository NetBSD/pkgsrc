# $NetBSD: Makefile,v 1.17 2019/04/05 13:05:22 adam Exp $

DISTNAME=	celery-4.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/celery/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.celeryproject.org/
COMMENT=	Asynchronous task/job queue based on distributed message passing
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-billiard>=3.6.0.0:../../parallel/py-billiard
DEPENDS+=	${PYPKGPREFIX}-kombu>=4.4.0:../../net/py-kombu
DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-vine>=1.3.0:../../devel/py-vine
TEST_DEPENDS+=	${PYPKGPREFIX}-case>=1.3.1:../../devel/py-case
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=3.0:../../devel/py-test

# Fix for Python 3.7 (async is a reserved keyword).
# https://github.com/celery/celery/pull/4879/files
pre-configure:
	cd ${WRKSRC}/celery/backends && ${MV} async.py asynchronous.py || ${TRUE}

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} celery celery-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
