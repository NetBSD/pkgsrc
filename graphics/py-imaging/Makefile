# $NetBSD: Makefile,v 1.15 2002/09/21 23:46:51 jlam Exp $

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
USE_BUILDLINK=	yes

do-configure:
	(cd ${WRKSRC}/libImaging && ${SETENV} ${CONFIGURE_ENV} ./configure \
	 ${CONFIGURE_ARGS} && ${SETENV} ${MAKE_ENV} ${MAKE})
	${SED} "s|@JPEGDIR@|${BUILDLINK_PREFIX.jpeg}|g" <${WRKSRC}/setup.py \
	 >${WRKSRC}/setup.py.tmp && ${MV} -f ${WRKSRC}/setup.py.tmp \
	 ${WRKSRC}/setup.py

.include "../../lang/python/extension.mk"
.include "../../graphics/jpeg/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
