# $NetBSD: Makefile,v 1.4 2018/01/18 09:18:06 adam Exp $

DISTNAME=	alembic-0.9.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/alembic/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://bitbucket.org/zzzeek/alembic
COMMENT=	Database migration tool for SQLAlchemy
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-dateutil-[0-9]*:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-editor>=0.3:../../editors/py-editor
DEPENDS+=	${PYPKGPREFIX}-nose>=1.3.0:../../devel/py-nose
DEPENDS+=	${PYPKGPREFIX}-sqlalchemy>=0.9.8:../../databases/py-sqlalchemy
BUILD_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} alembic alembic${PYVERSSUFFIX} || ${TRUE}

do-test:
	cd ${WRKSRC} && py.test-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
