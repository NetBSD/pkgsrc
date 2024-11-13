# $NetBSD: Makefile,v 1.12 2024/11/13 08:26:22 adam Exp $

DISTNAME=	mysqlclient-2.2.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mysqlclient/}

MAINTAINER=	wiedi@frubar.net
HOMEPAGE=	https://github.com/PyMySQL/mysqlclient-python
COMMENT=	MySQL database connector for Python
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=61:../../devel/py-setuptools

USE_TOOLS+=	pkg-config

# Testing requires a running MySQL server with user access.

.include "../../lang/python/wheel.mk"
.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
