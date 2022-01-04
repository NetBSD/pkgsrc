# $NetBSD: Makefile,v 1.54 2022/01/04 20:52:43 wiz Exp $

DISTNAME=	mysqlclient-1.3.10
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/mysqlclient/mysqldb/}
PKGREVISION=	2
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mysqlclient/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.org/project/mysqlclient/1.3.10/
COMMENT=	MySQL interface for Python
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c

PYPKGVER=	${PYPKGPREFIX:S/py//}

.include "../../lang/python/egg.mk"
.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
