# $NetBSD: Makefile,v 1.82 2016/12/11 11:25:52 darcy Exp $

DISTNAME=		PyGreSQL-5.0.3
PKGNAME=		${PYPKGPREFIX}-${DISTNAME:S/PyGreSQL/postgresql/}
CATEGORIES=		databases python
MASTER_SITES=		http://pygresql.org/files/

OWNER=			darcy@NetBSD.org
HOMEPAGE=		http://www.PyGreSQL.org/
COMMENT=		Python interface to PostgreSQL
LICENSE=        	postgresql-license

MAKE_ENV+=		MANDIR=${PREFIX}/${PKGMANDIR}
MAKE_ENV+=		BINDIR=${PREFIX}/bin
USE_TOOLS+=		gmake

MAKE_FILE=		GNUmakefile
MAKE_ENV+=		INSTALLED_LIBPQ=1

REPLACE_PYTHON=		pg.py pgdb.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
