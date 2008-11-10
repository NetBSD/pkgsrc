# $NetBSD: Makefile,v 1.18 2008/11/10 22:36:49 wiz Exp $

DISTNAME=	pysqlite-2.5.0a
PKGNAME=	${PYPKGPREFIX}-sqlite2-2.5.0a
CATEGORIES=	databases python
MASTER_SITES=	http://oss.itsystementwicklung.de/download/pysqlite/2.5/2.5.0/

MAINTAINER=	tsarna@NetBSD.org
HOMEPAGE=	http://pysqlite.org/
COMMENT=	SQLite database adapter for Python

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=	yes

# remove after 2.5.0a
WRKSRC=		${WRKDIR}/${DISTNAME:S/a$//}

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
