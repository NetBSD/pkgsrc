# $NetBSD: Makefile,v 1.13 2002/09/03 20:31:02 drochner Exp $

DISTNAME=	Imaging-1.1.3
PKGNAME=	${PYPKGPREFIX}-imaging-1.1.3
CATEGORIES=	graphics
MASTER_SITES=	http://www.pythonware.com/downloads/

MAINTAINER=	tsarna@netbsd.org
HOMEPAGE=	http://www.pythonware.com/products/pil/
COMMENT=	PIL, the Python Imaging Library

#DEPENDS+=	jpeg-6b:../../graphics/jpeg

DIST_SUBDIR=    python
PYDISTUTILSPKG= yes
PY_PATCHPLIST=	yes
GNU_CONGIGURE=	yes
USE_BUILDLINK2=	yes

do-configure:
	(cd ${WRKSRC}/libImaging && ${SETENV} ${CONFIGURE_ENV} ./configure \
	 ${CONFIGURE_ARGS} && ${SETENV} ${MAKE_ENV} ${MAKE})
	${SED} "s|@JPEGDIR@|${BUILDLINK_PREFIX.jpeg}|g" <${WRKSRC}/setup.py \
	 >${WRKSRC}/setup.py.tmp && ${MV} -f ${WRKSRC}/setup.py.tmp \
	 ${WRKSRC}/setup.py

.include "../../lang/python/extension.buildlink.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
