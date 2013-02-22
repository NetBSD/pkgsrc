# $NetBSD: Makefile,v 1.20 2013/02/22 19:59:06 shattered Exp $

DISTNAME=	pysqlite-1.0.1
PKGNAME=	${PYPKGPREFIX}-sqlite-1.0.1
PKGREVISION=	2
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pysqlite/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.pysqlite.org/
COMMENT=	SQLite database adapter for Python

PYDISTUTILSPKG=	yes
PY_PATCHPLIST=	yes
WRKSRC=		${WRKDIR}/pysqlite

.include "../../databases/sqlite/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../time/py-mxDateTime/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
