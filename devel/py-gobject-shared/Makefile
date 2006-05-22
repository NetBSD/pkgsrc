# $NetBSD: Makefile,v 1.4 2006/05/22 17:02:48 drochner Exp $

PKGNAME=		py-gobject-shared-2.10.1

.include "../../devel/py-gobject/Makefile.common"

PYTHON_FOR_BUILD_ONLY=	yes
INSTALLATION_DIRS=	include/pygtk-2.0 lib/pkgconfig

do-build:

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/include/pygtk-2.0
	${INSTALL_DATA} ${WRKSRC}/gobject/pygobject.h ${PREFIX}/include/pygtk-2.0
	${INSTALL_DATA_DIR} ${PREFIX}/lib/pkgconfig
	${INSTALL_DATA} ${WRKSRC}/pygobject-2.0.pc ${PREFIX}/lib/pkgconfig

.include "../../lang/python/application.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
