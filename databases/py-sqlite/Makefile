# $NetBSD: Makefile,v 1.11 2006/10/04 20:53:46 wiz Exp $

DISTNAME=	pysqlite-1.0.1
PKGNAME=	${PYPKGPREFIX}-sqlite-1.0.1
PKGREVISION=	1
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pysqlite/}

MAINTAINER=	tsarna@NetBSD.org
HOMEPAGE=	http://pysqlite.org/
COMMENT=	SQLite database adapter for Python

PYDISTUTILSPKG=	yes
PY_PATCHPLIST=	yes
PYTHON_VERSIONS_ACCEPTED=	24 23 22 21
WRKSRC=		${WRKDIR}/pysqlite

.include "../../databases/sqlite/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../time/py-mxDateTime/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
