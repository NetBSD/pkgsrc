# $NetBSD: Makefile,v 1.9 2017/07/25 11:03:19 adam Exp $

DISTNAME=	SQLAlchemy-Utils-0.32.14
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=S/SQLAlchemy-Utils/}

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	https://github.com/kvesteri/sqlalchemy-utils
COMMENT=	Various utility functions for SQLAlchemy
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-sqlalchemy>=1.0:../../databases/py-sqlalchemy

USE_LANGUAGES=	# none

.include "options.mk"

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
