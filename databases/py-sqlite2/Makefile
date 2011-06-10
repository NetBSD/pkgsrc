# $NetBSD: Makefile,v 1.24 2011/06/10 09:39:51 obache Exp $

DISTNAME=	pysqlite-2.6.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/pysqlite/sqlite2/}
PKGREVISION=	1
CATEGORIES=	databases python
MASTER_SITES=	http://pysqlite.googlecode.com/files/

MAINTAINER=	tsarna@NetBSD.org
HOMEPAGE=	http://pysqlite.googlecode.com/
COMMENT=	SQLite database adapter for Python
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/python/distutils.mk"

.if !defined(PYPACKAGE) || ${PYPACKAGE} != "python24"
PLIST.python25=	yes
.endif

PLIST_VARS+=	python25

do-postinstall-test: .PHONY
	cd ${WRKDIR} && ${PYTHONBIN} -c "from pysqlite2 import test;test.test()"

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
