# $NetBSD: Makefile,v 1.8 2015/10/12 10:00:57 fhajny Exp $

DISTNAME=	peewee-2.6.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=coleifer/}

MAINTAINER=	filip@joyent.com
HOMEPAGE=	http://www.peewee-orm.com/
COMMENT=	Small, expressive ORM for PostgreSQL, MySQL and SQLite
LICENSE=	mit

GITHUB_PROJECT=	peewee

USE_LANGUAGES=	c
USE_TOOLS+=	bash

MESSAGE_SUBST+=	PYPKGPREFIX=${PYPKGPREFIX}

REPLACE_BASH+=		playhouse/berkeley_build.sh
REPLACE_PYTHON+=	pwiz.py

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
