# $NetBSD: Makefile,v 1.5 2026/08/20 05:40:44 adam Exp $

DISTNAME=	svglib-2.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/svglib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/deeplook/svglib
COMMENT=	Pure-Python library for reading and converting SVG
LICENSE=	gnu-lgpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>0:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-Pillow>=9.0.0:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-cssselect2>=0.2.0:../../textproc/py-cssselect2
DEPENDS+=	${PYPKGPREFIX}-lxml>=6.0.0:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-reportlab>=4.4.3:../../print/py-reportlab
DEPENDS+=	${PYPKGPREFIX}-tinycss2>=0.6.0:../../textproc/py-tinycss2
# bitmaps
DEPENDS+=	${PYPKGPREFIX}-rlpycairo>=0.4.0:../../print/py-rlpycairo

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	svg2pdf

PYTHON_VERSIONS_INCOMPATIBLE=	310 311

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
