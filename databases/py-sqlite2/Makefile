# $NetBSD: Makefile,v 1.25 2012/04/08 19:08:48 wiz Exp $

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

do-postinstall-test: .PHONY
	cd ${WRKDIR} && ${PYTHONBIN} -c "from pysqlite2 import test;test.test()"

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
