# $NetBSD: Makefile,v 1.2 2026/11/04 06:38:22 wiz Exp $

DISTNAME=	img2pdf-0.6.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/img2pdf/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.org/project/img2pdf/
COMMENT=	Lossless conversion of raster images to PDF
LICENSE=	gnu-lgpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.2:../../devel/py-flit_core
DEPENDS+=	${PYPKGPREFIX}-Pillow-[0-9]*:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-pikepdf-[0-9]*:../../print/py-pikepdf
DEPENDS+=	colord-[0-9]*:../../graphics/colord
TEST_DEPENDS+=	${PYPKGPREFIX}-numpy-[0-9]*:../../math/py-numpy
TEST_DEPENDS+=	${PYPKGPREFIX}-scipy-[0-9]*:../../math/py-scipy
# convert
TEST_DEPENDS+=	ImageMagick-[0-9]*:../../graphics/ImageMagick
# pdfimages, pdftocairo
TEST_DEPENDS+=	poppler-utils-[0-9]*:../../print/poppler-utils
# exiftool
TEST_DEPENDS+=	p5-Image-ExifTool-[0-9]*:../../graphics/p5-Image-ExifTool
# jpegtopnm
TEST_DEPENDS+=	netpbm-[0-9]*:../../graphics/netpbm
# date --utc
TEST_DEPENDS+=	coreutils-[0-9]*:../../sysutils/coreutils

TOOLS_PATH.date=	${TOOLBASE}/gnu/bin/date

PYTHON_VERSIONS_INCOMPATIBLE=	311 # py-Pillow, py-pikepdf

# as of 0.6.3:
# 4 failed, 278 passed, 24 skipped, 5 warnings, 48 errors
# mostly due to lack of tiff support with
# PKG_DEFAULT_OPTIONS=-tiff

REPLACE_PYTHON+=	src/img2pdf.py

SUBST_CLASSES+=		icc
SUBST_FILES.icc+=	src/img2pdf.py
SUBST_SED.icc+=		-e "s,/usr/share/color/icc/sRGB.icc,${PREFIX}/share/color/icc/colord/sRGB.icc,"
SUBST_STAGE.icc=	pre-build
SUBST_MESSAGE.icc=	Fixing path to color profile.

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/img2pdf ${DESTDIR}${PREFIX}/bin/img2pdf${PYVERSSUFFIX}
	${MV} ${DESTDIR}${PREFIX}/bin/img2pdf-gui ${DESTDIR}${PREFIX}/bin/img2pdf-gui${PYVERSSUFFIX}

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
