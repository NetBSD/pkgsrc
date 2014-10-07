# $NetBSD: Makefile,v 1.4 2014/10/07 10:09:36 adam Exp $

DISTNAME=	mysql-connector-python-2.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/-python//}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_MYSQL:=Connector-Python/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://dev.mysql.com/downloads/connector/python/
COMMENT=	Standardized mysql database driver for Python development
LICENSE=	gnu-gpl-v2

EGG_NAME=	${DISTNAME:S/-/_/:S/-/_/}

.include "../../lang/python/distutils.mk"
.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
