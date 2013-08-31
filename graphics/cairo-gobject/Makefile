# $NetBSD: Makefile,v 1.27 2013/08/31 22:19:32 adam Exp $

.include "../../graphics/cairo/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-gobject-/}

BUILD_DIRS=	util/cairo-gobject
INSTALL_DIRS=	util/cairo-gobject

INSTALLATION_DIRS+=	lib/pkgconfig

.include "../../mk/bsd.prefs.mk"

post-install:
	${INSTALL_DATA} ${WRKSRC}/src/cairo-gobject.pc \
		${DESTDIR}${PREFIX}/lib/pkgconfig

.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
