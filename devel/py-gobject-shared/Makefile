# $NetBSD: Makefile,v 1.15 2009/06/09 13:25:02 wiz Exp $

PKGNAME=		py-gobject-shared-2.18.0

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../devel/py-gobject/Makefile.common"

PYTHON_FOR_BUILD_ONLY=	yes
INSTALLATION_DIRS=	include/pygtk-2.0 lib/pkgconfig

do-build:

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR:Q}${PREFIX:Q}/include/pygtk-2.0
	${INSTALL_DATA} ${WRKSRC}/gobject/pygobject.h \
		${DESTDIR:Q}${PREFIX:Q}/include/pygtk-2.0
	${INSTALL_DATA_DIR} ${DESTDIR:Q}${PREFIX:Q}/lib/pkgconfig
	${INSTALL_DATA} ${WRKSRC}/pygobject-2.0.pc \
		${DESTDIR:Q}${PREFIX:Q}/lib/pkgconfig

.include "../../lang/python/application.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
