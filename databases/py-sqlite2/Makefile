# $NetBSD: Makefile,v 1.9 2008/04/11 15:27:22 abs Exp $

DISTNAME=	pysqlite-2.3.5
PKGNAME=	${PYPKGPREFIX}-sqlite2-2.3.5
CATEGORIES=	databases python
MASTER_SITES=	http://initd.org/pub/software/pysqlite/releases/2.3/2.3.5/

MAINTAINER=	tsarna@NetBSD.org
HOMEPAGE=	http://initd.org/tracker/pysqlite
COMMENT=	SQLite database adapter for Python

PYDISTUTILSPKG=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	15 20 21 22

do-postinstall-test: .PHONY
	${PYTHONBIN} -c "from pysqlite2 import test;test.test()"

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
