# $NetBSD: Makefile,v 1.17 2002/10/24 20:44:51 drochner Exp $

DISTNAME=	Imaging-1.1.3
PKGNAME=	${PYPKGPREFIX}-imaging-1.1.3
CATEGORIES=	graphics
MASTER_SITES=	http://www.pythonware.com/downloads/

MAINTAINER=	tsarna@netbsd.org
HOMEPAGE=	http://www.pythonware.com/products/pil/
COMMENT=	PIL, the Python Imaging Library

DIST_SUBDIR=    python
PYDISTUTILSPKG= yes
PY_PATCHPLIST=	yes
GNU_CONFIGURE=	yes
USE_BUILDLINK2=	yes

do-configure:
	(cd ${WRKSRC}/libImaging && ${SETENV} ${CONFIGURE_ENV} ./configure \
	 ${CONFIGURE_ARGS} && ${SETENV} ${MAKE_ENV} ${MAKE})
	${SED} "s|@JPEGDIR@|${BUILDLINK_PREFIX.jpeg}|g" <${WRKSRC}/setup.py \
	 >${WRKSRC}/setup.py.tmp && ${MV} -f ${WRKSRC}/setup.py.tmp \
	 ${WRKSRC}/setup.py

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/${PYINC}/PIL
	(cd ${WRKSRC}/libImaging; ${INSTALL_DATA} \
		ImConfig.h ImPlatform.h Imaging.h \
		${PREFIX}/${PYINC}/PIL )

.include "../../lang/python/extension.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
