# $NetBSD: Makefile,v 1.1.1.1 2003/06/25 21:38:21 tsarna Exp $
#

DISTNAME=	pysqlite-0.4.3
PKGNAME=	${PYPKGPREFIX}-sqlite-0.4.3
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pysqlite/}

MAINTAINER=	tsarna@netbsd.org
HOMEPAGE=	http://pysqlite.sourceforge.net/
COMMENT=	SQLite database adapter for Python

USE_BUILDLINK2=	yes
PYDISTUTILSPKG=	yes
PY_PATCHPLIST=	yes

.include "../../databases/sqlite/buildlink2.mk"
.include "../../lang/python/extension.mk"
.include "../../time/py-mxDateTime/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
