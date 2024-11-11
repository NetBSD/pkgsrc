# $NetBSD: Makefile,v 1.18 2024/11/11 07:27:57 wiz Exp $

DISTNAME=	pymysql-1.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PyMySQL/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/PyMySQL/PyMySQL
COMMENT=	Pure-Python MySQL driver
LICENSE=	mit

WHEEL_NAME=	PyMySQL-${PKGVERSION_NOREV}

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=61:../../devel/py-setuptools
# rsa
PYTHON_VERSIONED_DEPENDENCIES+=	cryptography

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/versioned_dependencies.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
