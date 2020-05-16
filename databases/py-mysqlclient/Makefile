# $NetBSD: Makefile,v 1.6 2020/05/16 09:03:22 adam Exp $

DISTNAME=	mysqlclient-1.4.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mysqlclient/}

MAINTAINER=	wiedi@frubar.net
HOMEPAGE=	https://github.com/PyMySQL/mysqlclient-python
COMMENT=	MySQL database connector for Python
LICENSE=	gnu-gpl-v2

PYTHON_VERSIONED_DEPENDENCIES=	test:test

# testing requires a running MySQL server
do-test:
	cd ${WRKSRC} && pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
