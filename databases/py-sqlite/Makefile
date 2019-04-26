# $NetBSD: Makefile,v 1.27 2019/04/26 13:13:47 maya Exp $

DISTNAME=	pysqlite-1.0.1
PKGNAME=	${PYPKGPREFIX}-sqlite-1.0.1
PKGREVISION=	3
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pysqlite/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.pysqlite.org/
COMMENT=	SQLite database adapter for Python

WRKSRC=		${WRKDIR}/pysqlite

PYTHON_VERSIONS_INCOMPATIBLE=	 36 37 # py-mxDateTime

.include "../../databases/sqlite/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../time/py-mxDateTime/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
