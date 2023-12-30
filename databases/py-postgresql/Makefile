# $NetBSD: Makefile,v 1.89 2023/12/30 21:08:53 zafer Exp $

DISTNAME=	PyGreSQL-5.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/PyGreSQL/postgresql/}
PKGREVISION=	1
CATEGORIES=	databases python
MASTER_SITES=	https://pygresql.org/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.PyGreSQL.org/
COMMENT=	Python interface to PostgreSQL
LICENSE=	postgresql-license

REPLACE_PYTHON+=	pg.py
REPLACE_PYTHON+=	pgdb.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
