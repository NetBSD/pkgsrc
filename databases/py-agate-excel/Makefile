# $NetBSD: Makefile,v 1.3 2025/04/14 11:04:59 adam Exp $

DISTNAME=	agate-excel-0.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/agate-excel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://agate-excel.readthedocs.io/
COMMENT=	EXCEL read/write support to agate
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-agate-[0-9]*:../../devel/py-agate
DEPENDS+=	${PYPKGPREFIX}-olefile-[0-9]*:../../devel/py-olefile
DEPENDS+=	${PYPKGPREFIX}-openpyxl-[0-9]*:../../textproc/py-openpyxl
DEPENDS+=	${PYPKGPREFIX}-xlrd-[0-9]*:../../textproc/py-xlrd

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
