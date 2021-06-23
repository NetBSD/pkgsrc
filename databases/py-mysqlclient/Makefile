# $NetBSD: Makefile,v 1.7 2021/06/23 20:33:09 nia Exp $

DISTNAME=	mysqlclient-1.4.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
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
