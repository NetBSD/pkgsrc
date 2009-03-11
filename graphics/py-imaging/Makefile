# $NetBSD: Makefile,v 1.33 2009/03/11 21:58:52 wiz Exp $

DISTNAME=	Imaging-1.1.6
PKGNAME=	${PYPKGPREFIX}-imaging-1.1.6
CATEGORIES=	graphics python
MASTER_SITES=	http://effbot.org/downloads/

MAINTAINER=	tsarna@NetBSD.org
HOMEPAGE=	http://www.pythonware.com/products/pil/
COMMENT=	PIL, the Python Imaging Library

PKG_DESTDIR_SUPPORT=	user-destdir

DIST_SUBDIR=	python
PYDISTUTILSPKG= yes
PY_PATCHPLIST=	yes

FREETYPE_ROOT=	"${BUILDLINK_PREFIX.freetype2}/lib","${BUILDLINK_PREFIX.freetype2}/include"

SUBST_CLASSES=		ft2
SUBST_SED.ft2=		-e "s;FREETYPE_ROOT = None;FREETYPE_ROOT = ${FREETYPE_ROOT:Q};"
SUBST_FILES.ft2=	setup.py
SUBST_MESSAGE.ft2=	Fixing path to freetype2.
SUBST_STAGE.ft2=	pre-configure

INSTALLATION_DIRS=	${PYINC}/PIL

post-install:
	${INSTALL_DATA} ${WRKSRC}/libImaging/ImPlatform.h ${DESTDIR}${PREFIX}/${PYINC}/PIL
	${INSTALL_DATA} ${WRKSRC}/libImaging/Imaging.h ${DESTDIR}${PREFIX}/${PYINC}/PIL

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
