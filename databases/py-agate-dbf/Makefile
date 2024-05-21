# $NetBSD: Makefile,v 1.1 2024/05/21 13:03:14 cheusov Exp $

DISTNAME=	agate-dbf-0.2.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/agate-dbf/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://agate-dbf.readthedocs.io/en/latest/
COMMENT=	DBF read/write support to agate
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-agate-[0-9]*:../../devel/py-agate
DEPENDS+=	${PYPKGPREFIX}-dbfread-[0-9]*:../../databases/py-dbfread

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
