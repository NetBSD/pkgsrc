# $NetBSD: Makefile,v 1.25 2008/08/06 17:16:49 mjl Exp $

DISTNAME=	MySQL-python-${PKGVER}
PKGNAME=	${PYPKGPREFIX}-mysqldb-${PKGVER}
PKGVER=	1.2.2
# PKGREVISION=	3
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mysql-python/}

MAINTAINER=	tsarna@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/mysql-python
COMMENT=	MySQL interface for Python

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=	yes
PYBINMODULE=	yes
PY_PATCHPLIST=	yes
PYSETUPINSTALLARGS= --single-version-externally-managed --record plist.txt
PLIST_SUBST+=   PYVERSSUFFIX=${PYVERSSUFFIX}

PYTHON_VERSIONS_ACCEPTED=	25 24 23

.include "../../mk/mysql.buildlink3.mk"

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
