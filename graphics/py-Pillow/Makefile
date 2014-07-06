# $NetBSD: Makefile,v 1.10 2014/07/06 12:15:53 obache Exp $

DISTNAME=	Pillow-2.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics python
MASTER_SITES=	https://pypi.python.org/packages/source/P/Pillow/
EXTRACT_SUFX=	.zip

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://python-imaging.github.io/
COMMENT=	Python Imaging Library (Fork)

CONFLICTS+=	${PYPKGPREFIX}-imaging-[0-9]*

SUBST_CLASSES=		fix-path
SUBST_MESSAGE.fix-path=	Fixing paths.
SUBST_STAGE.fix-path=	pre-configure
SUBST_FILES.fix-path=	setup.py
SUBST_SED.fix-path=	-e 's,/usr/pkg,${PREFIX},'
SUBST_SED.fix-path+=	-e 's,JPEG_ROOT = None,JPEG_ROOT = _lib_include("${BUILDLINK_PREFIX.jpeg}"),'
SUBST_SED.fix-path+=	-e 's,JPEG2K_ROOT = None,JPEG2K_ROOT = _lib_include("${BUILDLINK_PREFIX.openjpeg}"),'
SUBST_SED.fix-path+=	-e 's,ZLIB_ROOT = None,ZLIB_ROOT = _lib_include("${BUILDLINK_PREFIX.zlib}"),'
SUBST_SED.fix-path+=	-e 's,TIFF_ROOT = None,TIFF_ROOT = _lib_include("${BUILDLINK_PREFIX.tiff}"),'
SUBST_SED.fix-path+=	-e 's,FREETYPE_ROOT = None,FREETYPE_ROOT = _lib_include("${BUILDLINK_PREFIX.freetype2}"),'
SUBST_SED.fix-path+=	-e 's,LCMS_ROOT = None,LCMS_ROOT = _lib_include("${BUILDLINK_PREFIX.lcms2}"),'

do-test:
	${RUN}cd ${WRKSRC};${PKGSRC_SETENV} ${TEST_ENV} ${PYTHONBIN} selftest.py

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../graphics/openjpeg/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
