# $NetBSD: Makefile,v 1.19 2025/03/05 09:34:24 wiz Exp $

DISTNAME=	pymysql-1.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PyMySQL/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/PyMySQL/PyMySQL
COMMENT=	Pure-Python MySQL driver
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=75.8.2:../../devel/py-setuptools
# rsa
PYTHON_VERSIONED_DEPENDENCIES+=	cryptography

USE_LANGUAGES=	# none

.include "../../lang/python/versioned_dependencies.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
