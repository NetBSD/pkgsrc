# $NetBSD: Makefile,v 1.2 2006/05/22 14:38:16 tron Exp $

PKGNAME=		py-gobject-shared-2.10.1

.include "../../devel/py-gobject/Makefile.common"

.if defined(_PYTHON_VERSION)
PYTHON_VERSION_REQD=	${_PYTHON_VERSION}
else
PYTHON_VERSION_REQD=	${PYTHON_VERSION_DEFAULT}
.endif

PYTHON_FOR_BUILD_ONLY=	yes
INSTALLATION_DIRS=	include/pygtk-2.0 lib/pkgconfig

do-build:

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/include/pygtk-2.0
	${INSTALL_DATA} ${WRKSRC}/gobject/pygobject.h ${PREFIX}/include/pygtk-2.0
	${INSTALL_DATA_DIR} ${PREFIX}/lib/pkgconfig
	${INSTALL_DATA} ${WRKSRC}/pygobject-2.0.pc ${PREFIX}/lib/pkgconfig

.include "../../lang/python/extension.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
