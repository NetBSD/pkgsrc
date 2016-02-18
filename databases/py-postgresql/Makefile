# $NetBSD: Makefile,v 1.76 2016/02/18 18:38:38 darcy Exp $

DISTNAME=		PyGreSQL-4.2.1
PKGNAME=		${PYPKGPREFIX}-postgresql-4.2.1
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

PY_PATCHPLIST=		yes
PLIST_SUBST+=		PYPKGPREFIX=${PYPKGPREFIX:Q}
REPLACE_PYTHON=		pg.py pgdb.py
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35 # not yet ported as of 4.1.1

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
