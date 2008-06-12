# $NetBSD: Makefile,v 1.11 2008/06/12 02:14:20 joerg Exp $

DISTNAME=	pysqlite-2.3.5
PKGNAME=	${PYPKGPREFIX}-sqlite2-2.3.5
CATEGORIES=	databases python
MASTER_SITES=	http://initd.org/pub/software/pysqlite/releases/2.3/2.3.5/

MAINTAINER=	tsarna@NetBSD.org
HOMEPAGE=	http://initd.org/tracker/pysqlite
COMMENT=	SQLite database adapter for Python

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=	yes

do-postinstall-test: .PHONY
	${PYTHONBIN} -c "from pysqlite2 import test;test.test()"

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
