# $NetBSD: Makefile,v 1.32 2022/01/04 20:52:45 wiz Exp $

DISTNAME=	SQLAlchemy-Utils-0.36.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
PKGREVISION=	1
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=S/SQLAlchemy-Utils/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kvesteri/sqlalchemy-utils
COMMENT=	Various utility functions for SQLAlchemy
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-sqlalchemy>=1.0:../../databases/py-sqlalchemy

USE_LANGUAGES=	# none

.include "options.mk"

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
