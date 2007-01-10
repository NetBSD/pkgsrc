# $NetBSD: Makefile,v 1.3 2007/01/10 10:39:18 drochner Exp $

DISTNAME=	pysqlite-2.3.2
PKGNAME=	${PYPKGPREFIX}-sqlite2-2.3.2
CATEGORIES=	databases python
MASTER_SITES=	http://initd.org/pub/software/pysqlite/releases/2.3/2.3.2/

MAINTAINER=	tsarna@NetBSD.org
HOMEPAGE=	http://initd.org/tracker/pysqlite
COMMENT=	SQLite database adapter for Python

PYDISTUTILSPKG=	yes

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
