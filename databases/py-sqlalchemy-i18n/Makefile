# $NetBSD: Makefile,v 1.3 2016/06/08 17:43:23 wiz Exp $

DISTNAME=	SQLAlchemy-i18n-1.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=S/SQLAlchemy-i18n/}

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	https://github.com/kvesteri/sqlalchemy-i18n
COMMENT=	Internationalization extension for SQLAlchemy models
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-sqlalchemy>=0.9:../../databases/py-sqlalchemy
DEPENDS+=	${PYPKGPREFIX}-sqlalchemy-utils>=0.25.3:../../databases/py-sqlalchemy-utils
DEPENDS+=	${PYPKGPREFIX}-six>=1.4.1:../../lang/py-six

USE_LANGUAGES=	# none

.include "options.mk"

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
