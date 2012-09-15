# $NetBSD: Makefile,v 1.34 2012/09/15 15:03:23 obache Exp $

DISTNAME=	MySQL-python-${DIST_VERSION}
PKGNAME=	${PYPKGPREFIX}-mysqldb-${DIST_VERSION:S/c/rc/}
DIST_VERSION=	1.2.3
PKGREVISION=	2
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mysql-python/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/mysql-python
COMMENT=	MySQL interface for Python
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-setuptools>=0.6c6:../../devel/py-setuptools

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=	yes
PY_PATCHPLIST=	yes
PYSETUPINSTALLARGS= --single-version-externally-managed --record plist.txt
PLIST_SUBST+=   DIST_VERSION=${DIST_VERSION} PYVERSSUFFIX=${PYVERSSUFFIX}


.include "../../mk/mysql.buildlink3.mk"

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
