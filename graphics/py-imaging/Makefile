# $NetBSD: Makefile,v 1.49 2014/05/15 06:23:05 spz Exp $

DISTNAME=	Imaging-1.1.7
PKGNAME=	${PYPKGPREFIX}-imaging-1.1.7
PKGREVISION=	8
CATEGORIES=	graphics python
MASTER_SITES=	http://effbot.org/media/downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.pythonware.com/products/pil/
COMMENT=	PIL, the Python Imaging Library

DIST_SUBDIR=	python
EGG_NAME=	PIL-${PKGVERSION_NOREV}

SUBST_CLASSES=		fix-path
SUBST_MESSAGE.fix-path=	Fixing paths.
SUBST_STAGE.fix-path=	pre-configure
SUBST_FILES.fix-path=	setup.py
SUBST_SED.fix-path=	-e 's,/usr/local,${PREFIX},'
SUBST_SED.fix-path+=	-e 's,FREETYPE_ROOT = None,FREETYPE_ROOT = libinclude("${BUILDLINK_PREFIX.freetype2}"),'

INSTALLATION_DIRS=	${PYINC}/PIL

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 1.1.7, use Pillow instead

post-install:
	${INSTALL_DATA} ${WRKSRC}/libImaging/ImPlatform.h ${DESTDIR}${PREFIX}/${PYINC}/PIL
	${INSTALL_DATA} ${WRKSRC}/libImaging/Imaging.h ${DESTDIR}${PREFIX}/${PYINC}/PIL

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/lcms/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
