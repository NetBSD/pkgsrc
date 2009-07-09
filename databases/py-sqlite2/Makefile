# $NetBSD: Makefile,v 1.19 2009/07/09 19:02:58 drochner Exp $

DISTNAME=	pysqlite-2.5.5
PKGNAME=	${PYPKGPREFIX}-sqlite2-2.5.5
CATEGORIES=	databases python
MASTER_SITES=	http://oss.itsystementwicklung.de/download/pysqlite/2.5/2.5.5/

MAINTAINER=	tsarna@NetBSD.org
HOMEPAGE=	http://pysqlite.org/
COMMENT=	SQLite database adapter for Python

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"

.if defined(PYPACKAGE) && \
    (${PYPACKAGE} == "python23" || ${PYPACKAGE} == "python24")
pre-configure:
	rm ${WRKSRC}/pysqlite2/test/py25tests.py
.else
PLIST.python25=	yes
.endif

PLIST_VARS+=	python25

do-postinstall-test: .PHONY
	cd ${WRKDIR} && ${PYTHONBIN} -c "from pysqlite2 import test;test.test()"

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
