# $NetBSD: Makefile,v 1.22 2011/01/27 16:49:32 gdt Exp $

DISTNAME=	pysqlite-2.6.0
PKGNAME=	${PYPKGPREFIX}-sqlite2-2.6.0
PKGREVISION=	1
CATEGORIES=	databases python
MASTER_SITES=	http://pysqlite.googlecode.com/files/

MAINTAINER=	tsarna@NetBSD.org
HOMEPAGE=	http://pysqlite.googlecode.com/
COMMENT=	SQLite database adapter for Python

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
