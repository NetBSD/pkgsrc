# $NetBSD: Makefile,v 1.57 2019/07/03 07:19:03 nia Exp $

DISTNAME=	pysqlite-2.8.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/pysqlite/sqlite2/}
PKGREVISION=	4
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pysqlite/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ghaering/pysqlite
COMMENT=	SQLite database adapter for Python
LICENSE=	mit

PYTHON_VERSIONS_INCOMPATIBLE=	36 37 # not yet ported as of 2.6.3

.PHONY: do-postinstall-test
do-postinstall-test:
	cd ${WRKDIR} && ${PYTHONBIN} -c "from pysqlite2 import test;test.test()"

.include "../../lang/python/distutils.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
