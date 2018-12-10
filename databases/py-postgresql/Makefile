# $NetBSD: Makefile,v 1.85 2018/12/10 15:11:14 adam Exp $

DISTNAME=	PyGreSQL-5.0.6
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
