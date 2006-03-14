# $NetBSD: Makefile,v 1.1.1.1 2006/03/14 20:17:59 drochner Exp $

DISTNAME=	pysqlite-2.0.7
PKGNAME=	${PYPKGPREFIX}-sqlite2-2.0.7
CATEGORIES=	databases python
MASTER_SITES=	http://initd.org/pub/software/pysqlite/releases/2.0/2.0.7/

MAINTAINER=	tsarna@NetBSD.org
HOMEPAGE=	http://initd.org/tracker/pysqlite
COMMENT=	SQLite database adapter for Python

PYDISTUTILSPKG=	yes
# XXX version specific setuptools, should add something to extension.mk
PYTHON_VERSIONS_ACCEPTED= 24
DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py24-setuptools

TESTCMD=	from lib import test; \
		test.test()

do-test:
	cd ${WRKSRC} && ${PYTHONBIN} -c ${TESTCMD:Q}

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../time/py-mxDateTime/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
