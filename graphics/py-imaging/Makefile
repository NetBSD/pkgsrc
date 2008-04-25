# $NetBSD: Makefile,v 1.31 2008/04/25 19:46:49 joerg Exp $

DISTNAME=	Imaging-1.1.6
PKGNAME=	${PYPKGPREFIX}-imaging-1.1.6
CATEGORIES=	graphics python
MASTER_SITES=	http://effbot.org/downloads/

MAINTAINER=	tsarna@NetBSD.org
HOMEPAGE=	http://www.pythonware.com/products/pil/
COMMENT=	PIL, the Python Imaging Library

PKG_DESTDIR_SUPPORT=	user-destdir

PYTHON_VERSIONS_ACCEPTED=	25 24 23 21

DIST_SUBDIR=	python
PYDISTUTILSPKG= yes
PY_PATCHPLIST=	yes

INSTALLATION_DIRS=	${PYINC}/PIL

post-install:
	${INSTALL_DATA} ${WRKSRC}/libImaging/ImPlatform.h ${DESTDIR}${PREFIX}/${PYINC}/PIL
	${INSTALL_DATA} ${WRKSRC}/libImaging/Imaging.h ${DESTDIR}${PREFIX}/${PYINC}/PIL

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
