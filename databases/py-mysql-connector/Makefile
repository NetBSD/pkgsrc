# $NetBSD: Makefile,v 1.10 2021/06/23 20:33:09 nia Exp $

DISTNAME=	mysql-connector-python-2.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/-python//}
PKGREVISION=	1
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_MYSQL:=Connector-Python/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://dev.mysql.com/downloads/connector/python/
COMMENT=	Standardized mysql database driver for Python development
LICENSE=	gnu-gpl-v2

.include "../../lang/python/distutils.mk"
.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
