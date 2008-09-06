# $NetBSD: Makefile,v 1.13 2008/09/06 16:12:44 wiz Exp $

DISTNAME=	pysqlite-2.5.0
PKGNAME=	${PYPKGPREFIX}-sqlite2-2.5.0
CATEGORIES=	databases python
MASTER_SITES=	http://oss.itsystementwicklung.de/download/pysqlite/2.5/2.5.0/

MAINTAINER=	tsarna@NetBSD.org
HOMEPAGE=	http://pysqlite.org/
COMMENT=	SQLite database adapter for Python

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=	yes

do-postinstall-test: .PHONY
	${PYTHONBIN} -c "from pysqlite2 import test;test.test()"

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
