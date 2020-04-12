# $NetBSD: Makefile,v 1.59 2020/04/12 08:28:26 adam Exp $

DISTNAME=	pysqlite-2.8.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/pysqlite/sqlite2/}
PKGREVISION=	5
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pysqlite/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ghaering/pysqlite
COMMENT=	SQLite database adapter for Python
LICENSE=	mit

PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported as of 2.6.3

.PHONY: do-postinstall-test
do-postinstall-test:
	cd ${WRKDIR} && ${PYTHONBIN} -c "from pysqlite2 import test;test.test()"

.include "../../lang/python/distutils.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
