# $NetBSD: Makefile,v 1.21 2023/11/02 12:20:03 wiz Exp $

DISTNAME=	willow-1.6.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^w/W/}
PKGREVISION=	1
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=W/Willow/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/wagtail/Willow
COMMENT=	Wrapper library for Pillow, OpenCV and Wand
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.2:../../devel/py-flit_core
DEPENDS+=	${PYPKGPREFIX}-defusedxml>=0.7:../../textproc/py-defusedxml
DEPENDS+=	${PYPKGPREFIX}-filetype>=1.1.1:../../sysutils/py-filetype
# heif
DEPENDS+=	${PYPKGPREFIX}-pillow_heif>=0.10.0:../../graphics/py-pillow_heif

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../graphics/opencv/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
