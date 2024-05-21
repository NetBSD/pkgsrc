# $NetBSD: Makefile,v 1.1 2024/05/21 13:07:36 cheusov Exp $

DISTNAME=	agate-excel-0.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/agate-excel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://agate-excel.readthedocs.io/
COMMENT=	EXCEL read/write support to agate
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-agate-[0-9]*:../../devel/py-agate
DEPENDS+=	${PYPKGPREFIX}-olefile-[0-9]*:../../devel/py-olefile
DEPENDS+=	${PYPKGPREFIX}-openpyxl-[0-9]*:../../textproc/py-openpyxl
DEPENDS+=	${PYPKGPREFIX}-xlrd-[0-9]*:../../textproc/py-xlrd

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
