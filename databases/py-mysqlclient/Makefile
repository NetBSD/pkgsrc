# $NetBSD: Makefile,v 1.11 2024/11/11 07:27:57 wiz Exp $

DISTNAME=	mysqlclient-2.2.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mysqlclient/}

MAINTAINER=	wiedi@frubar.net
HOMEPAGE=	https://github.com/PyMySQL/mysqlclient-python
COMMENT=	MySQL database connector for Python
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

USE_TOOLS+=	pkg-config

PYTHON_VERSIONS_INCOMPATIBLE=	27

# Testing requires a running MySQL server with user access.

.include "../../lang/python/wheel.mk"
.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
