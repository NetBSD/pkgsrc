# $NetBSD: Makefile,v 1.20 2004/05/02 03:55:16 snj Exp $

DISTNAME=	Imaging-1.1.4
PKGNAME=	${PYPKGPREFIX}-imaging-1.1.4
CATEGORIES=	graphics
MASTER_SITES=	http://effbot.org/downloads/

MAINTAINER=	tsarna@NetBSD.org
HOMEPAGE=	http://www.pythonware.com/products/pil/
COMMENT=	PIL, the Python Imaging Library

DIST_SUBDIR=    python
PYDISTUTILSPKG= yes
PY_PATCHPLIST=	yes
GNU_CONFIGURE=	yes
USE_BUILDLINK3=	yes

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
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
