# $NetBSD: Makefile,v 1.80 2016/09/13 23:59:37 wiz Exp $

DISTNAME=		PyGreSQL-5.0.2
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
