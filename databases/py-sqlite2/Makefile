# $NetBSD: Makefile,v 1.47 2017/09/18 09:53:14 maya Exp $

DISTNAME=	pysqlite-2.6.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/pysqlite/sqlite2/}
PKGREVISION=	14
CATEGORIES=	databases python
#MASTER_SITES=	https://pypi.python.org/pypi/pysqlite/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	https://pypi.python.org/pypi/pysqlite/
COMMENT=	SQLite database adapter for Python
LICENSE=	mit

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # not yet ported as of 2.6.3

.PHONY: do-postinstall-test
do-postinstall-test:
	cd ${WRKDIR} && ${PYTHONBIN} -c "from pysqlite2 import test;test.test()"

.include "../../lang/python/distutils.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
