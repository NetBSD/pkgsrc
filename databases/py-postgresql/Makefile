# $NetBSD: Makefile,v 1.75 2016/01/22 19:57:05 darcy Exp $

DISTNAME=		PyGreSQL-4.2
PKGNAME=		${PYPKGPREFIX}-postgresql-4.2
CATEGORIES=		databases python
MASTER_SITES=		http://pygresql.org/files/
EXTRACT_SUFX=		.tar.gz

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

DOCDIR=			${PREFIX}/share/doc/${PYPKGPREFIX}-postgresql

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
