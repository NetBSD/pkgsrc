# $NetBSD: Makefile,v 1.16 2023/08/27 03:38:59 adam Exp $

DISTNAME=	willow-1.6.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^w/W/}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=W/Willow/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/wagtail/Willow
COMMENT=	Wrapper library for Pillow, OpenCV and Wand
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-defusedxml>=0.7:../../textproc/py-defusedxml
DEPENDS+=	${PYPKGPREFIX}-filetype>=1.1.1:../../sysutils/py-filetype
# heif
DEPENDS+=	${PYPKGPREFIX}-pillow_heif>=0.10.0:../../graphics/py-pillow_heif

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../graphics/opencv/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
