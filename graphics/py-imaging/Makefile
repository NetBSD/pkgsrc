# $NetBSD: Makefile,v 1.39 2011/01/03 12:17:30 adam Exp $

DISTNAME=	Imaging-1.1.7
PKGNAME=	${PYPKGPREFIX}-imaging-1.1.7
PKGREVISION=	2
CATEGORIES=	graphics python
MASTER_SITES=	http://effbot.org/media/downloads/

MAINTAINER=	tsarna@NetBSD.org
HOMEPAGE=	http://www.pythonware.com/products/pil/
COMMENT=	PIL, the Python Imaging Library

PKG_DESTDIR_SUPPORT=	user-destdir

DIST_SUBDIR=	python
PYDISTUTILSPKG= yes
PY_PATCHPLIST=	yes

SUBST_CLASSES=		fix-path
SUBST_MESSAGE.fix-path=	Fixing paths.
SUBST_STAGE.fix-path=	pre-configure
SUBST_FILES.fix-path=	setup.py
SUBST_SED.fix-path=	-e 's,/usr/local,${PREFIX},'
SUBST_SED.fix-path+=	-e 's,FREETYPE_ROOT = None,FREETYPE_ROOT = libinclude("${BUILDLINK_PREFIX.freetype2}"),'

INSTALLATION_DIRS=	${PYINC}/PIL

post-install:
	${INSTALL_DATA} ${WRKSRC}/libImaging/ImPlatform.h ${DESTDIR}${PREFIX}/${PYINC}/PIL
	${INSTALL_DATA} ${WRKSRC}/libImaging/Imaging.h ${DESTDIR}${PREFIX}/${PYINC}/PIL

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/lcms/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
