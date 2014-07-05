# $NetBSD: Makefile,v 1.1 2014/07/05 19:40:25 rodent Exp $

DISTNAME=	SQLAlchemy-Utils-0.26.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	databases python
MASTER_SITES=	https://pypi.python.org/packages/source/S/SQLAlchemy-Utils/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	https://github.com/kvesteri/sqlalchemy-utils
COMMENT=	Various utility functions for SQLAlchemy
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-sqlalchemy>=0.9.3:../../databases/py-sqlalchemy

USE_LANGUAGES=	# none

.include "options.mk"

EGG_NAME=	${DISTNAME:S/-/_/1}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
