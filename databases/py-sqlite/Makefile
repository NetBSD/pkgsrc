# $NetBSD: Makefile,v 1.7 2005/02/24 19:26:37 drochner Exp $

DISTNAME=	pysqlite-1.0.1
PKGNAME=	${PYPKGPREFIX}-sqlite-1.0.1
CATEGORIES=	databases python
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
