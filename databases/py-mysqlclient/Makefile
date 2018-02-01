# $NetBSD: Makefile,v 1.1 2018/02/01 22:20:08 fhajny Exp $

DISTNAME=	mysqlclient-python-1.3.12
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=PyMySQL/}
GITHUB_PROJECT=	mysqlclient-python
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	wiedi@frubar.net
HOMEPAGE=	https://github.com/PyMySQL/mysqlclient-python/
COMMENT=	MySQL database connector for Python
LICENSE=	gnu-gpl-v2

EGG_NAME=	mysqlclient-${PKGVERSION_NOREV}

.include "../../lang/python/egg.mk"
.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
