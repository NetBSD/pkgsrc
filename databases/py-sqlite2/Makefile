# $NetBSD: Makefile,v 1.30 2013/02/21 15:14:45 gdt Exp $

DISTNAME=	pysqlite-2.6.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/pysqlite/sqlite2/}
PKGREVISION=	4
CATEGORIES=	databases python
MASTER_SITES=	http://pysqlite.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pysqlite.googlecode.com/
COMMENT=	SQLite database adapter for Python
LICENSE=	mit

.include "../../lang/python/distutils.mk"

do-postinstall-test: .PHONY
	cd ${WRKDIR} && ${PYTHONBIN} -c "from pysqlite2 import test;test.test()"

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
