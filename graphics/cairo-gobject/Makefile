# $NetBSD: Makefile,v 1.30 2015/04/25 14:23:07 tnn Exp $

PKGREVISION= 1
.include "../../graphics/cairo/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-gobject-/}

BUILD_DIRS=	util/cairo-gobject
INSTALL_DIRS=	util/cairo-gobject

INSTALLATION_DIRS+=	lib/pkgconfig

.include "../../mk/bsd.prefs.mk"

post-install:
	${INSTALL_DATA} ${WRKSRC}/src/cairo-gobject.pc \
		${DESTDIR}${PREFIX}/lib/pkgconfig

BUILDLINK_ABI_DEPENDS.glib2+=	glib2>=2.14.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
