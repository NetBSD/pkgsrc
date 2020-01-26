# $NetBSD: Makefile,v 1.30 2020/01/26 17:30:53 rillig Exp $

DISTNAME=	pysqlite-1.0.1
PKGNAME=	${PYPKGPREFIX}-sqlite-1.0.1
PKGREVISION=	3
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pysqlite/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.pysqlite.org/
COMMENT=	SQLite database adapter for Python

WRKSRC=		${WRKDIR}/pysqlite

PYTHON_VERSIONS_ACCEPTED=	27 # py-mxDateTime

.include "../../databases/sqlite/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../time/py-mxDateTime/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
