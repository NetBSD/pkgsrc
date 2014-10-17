# $NetBSD: Makefile,v 1.1 2014/10/17 10:24:04 fhajny Exp $

DISTNAME=	peewee-2.3.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases
MASTER_SITES=	-https://github.com/coleifer/peewee/archive/${PKGVERSION_NOREV}${EXTRACT_SUFX}

MAINTAINER=	filip@joyent.com
HOMEPAGE=	http://www.peewee-orm.com/
COMMENT=	Small, expressive ORM for PostgreSQL, MySQL and SQLite
LICENSE=	mit

USE_LANGUAGES=	# none

MESSAGE_SUBST+=	PYPKGPREFIX=${PYPKGPREFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
