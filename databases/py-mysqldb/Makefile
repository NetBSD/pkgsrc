# $NetBSD: Makefile,v 1.55 2022/08/26 16:23:10 tron Exp $

DISTNAME=	mysqlclient-2.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/mysqlclient/mysqldb/}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mysqlclient/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.org/project/mysqlclient/${PKGVERSION_NOREV}/
COMMENT=	MySQL interface for Python
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c

PYPKGVER=	${PYPKGPREFIX:S/py//}

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
