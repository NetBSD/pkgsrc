# $NetBSD: Makefile,v 1.86 2019/05/21 19:46:39 david Exp $

DISTNAME=	PyGreSQL-5.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/PyGreSQL/postgresql/}
CATEGORIES=	databases python
MASTER_SITES=	http://pygresql.org/files/

OWNER=		darcy@NetBSD.org
HOMEPAGE=	http://www.PyGreSQL.org/
COMMENT=	Python interface to PostgreSQL
LICENSE=	postgresql-license

REPLACE_PYTHON+=	pg.py
REPLACE_PYTHON+=	pgdb.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
