# $NetBSD: Makefile,v 1.3 2004/03/31 06:07:06 snj Exp $

DISTNAME=	pysqlite-0.5.0
PKGNAME=	${PYPKGPREFIX}-sqlite-0.5.0
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pysqlite/}

MAINTAINER=	tsarna@NetBSD.org
HOMEPAGE=	http://pysqlite.sourceforge.net/
COMMENT=	SQLite database adapter for Python

PYDISTUTILSPKG=	yes
PY_PATCHPLIST=	yes
USE_BUILDLINK3=	yes
WRKSRC=		${WRKDIR}/pysqlite

.include "../../databases/sqlite/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../time/py-mxDateTime/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
