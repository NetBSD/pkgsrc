# $NetBSD: Makefile,v 1.6 2007/01/20 17:28:37 wiz Exp $

DISTNAME=	pysqlite-2.3.3
PKGNAME=	${PYPKGPREFIX}-sqlite2-2.3.3
CATEGORIES=	databases python
MASTER_SITES=	http://initd.org/pub/software/pysqlite/releases/2.3/2.3.3/

MAINTAINER=	tsarna@NetBSD.org
HOMEPAGE=	http://initd.org/tracker/pysqlite
COMMENT=	SQLite database adapter for Python

PYDISTUTILSPKG=	yes
PYTHON_VERSIONS_ACCEPTED=	24 23

do-test:
	${PYTHONBIN} -c "from pysqlite2 import test;test.test()"

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
