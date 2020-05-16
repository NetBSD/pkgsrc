# $NetBSD: Makefile,v 1.5 2020/05/16 08:46:42 adam Exp $

DISTNAME=	mysqlclient-1.4.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mysqlclient/}

MAINTAINER=	wiedi@frubar.net
HOMEPAGE=	https://github.com/PyMySQL/mysqlclient-python
COMMENT=	MySQL database connector for Python
LICENSE=	gnu-gpl-v2

PYTHON_VERSIONED_DEPENDENCIES=	pytest:test

# testing requires a running MySQL server
do-test:
	cd ${WRKSRC} && pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
