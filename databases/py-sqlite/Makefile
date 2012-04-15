# $NetBSD: Makefile,v 1.17 2012/04/15 22:00:59 wiz Exp $

DISTNAME=	pysqlite-1.0.1
PKGNAME=	${PYPKGPREFIX}-sqlite-1.0.1
PKGREVISION=	1
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pysqlite/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pysqlite.org/
COMMENT=	SQLite database adapter for Python

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=	yes
PY_PATCHPLIST=	yes
WRKSRC=		${WRKDIR}/pysqlite

.include "../../databases/sqlite/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../time/py-mxDateTime/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
