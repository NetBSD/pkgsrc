# $NetBSD: Makefile,v 1.14 2016/10/26 14:28:16 fhajny Exp $

DISTNAME=	peewee-2.8.5
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

PYDISTUTILSPKG=		yes

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
