# $NetBSD: Makefile,v 1.38 2014/01/25 10:29:59 wiz Exp $

DISTNAME=	MySQL-python-${DIST_VERSION}
PKGNAME=	${PYPKGPREFIX}-mysqldb-${DIST_VERSION:S/c/rc/}
DIST_VERSION=	1.2.3
PKGREVISION=	3
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mysql-python/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/mysql-python
COMMENT=	MySQL interface for Python
LICENSE=	gnu-gpl-v2

EGG_NAME=	${DISTNAME:S/MySQL-/MySQL_/}
PYTHON_VERSIONS_INCOMPATIBLE=	33 # not yet ported as of 1.2.3

.include "../../mk/mysql.buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
