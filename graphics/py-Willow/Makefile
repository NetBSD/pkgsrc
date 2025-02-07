# $NetBSD: Makefile,v 1.33 2025/02/07 21:58:00 wiz Exp $

DISTNAME=	willow-1.9.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^w/W/}
PKGREVISION=	2
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
DEPENDS+=	${PYPKGPREFIX}-pillow_heif>=0.13.0:../../graphics/py-pillow_heif

.include "../../graphics/opencv/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
