# $NetBSD: Makefile,v 1.2 2024/11/11 07:27:56 wiz Exp $

DISTNAME=	agate-sql-0.7.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/agate-sql/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://agate-sql.readthedocs.io/
COMMENT=	SQL read/write support to agate
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-agate-[0-9]*:../../devel/py-agate
DEPENDS+=	${PYPKGPREFIX}-sqlalchemy-[0-9]*:../../databases/py-sqlalchemy
DEPENDS+=	${PYPKGPREFIX}-sqlalchemy-utils-[0-9]*:../../databases/py-sqlalchemy-utils

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
