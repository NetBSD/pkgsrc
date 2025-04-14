# $NetBSD: Makefile,v 1.20 2025/04/14 11:31:12 adam Exp $

DISTNAME=	pymysql-1.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PyMySQL/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/PyMySQL/PyMySQL
COMMENT=	Pure-Python MySQL driver
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
# rsa
PYTHON_VERSIONED_DEPENDENCIES+=	cryptography

USE_LANGUAGES=	# none

.include "../../lang/python/versioned_dependencies.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
