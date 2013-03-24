# $NetBSD: Makefile,v 1.51 2013/03/24 07:09:25 spz Exp $
#

.include "../../print/poppler/Makefile.common"

PKGNAME=		poppler-glib-${POPPLER_VERS}

COMMENT=		PDF rendering library (GLib wrapper)
MAINTAINER=		reed@reedmedia.net

CONFLICTS+=		poppler<0.4.5nb1

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake
PKGCONFIG_OVERRIDE+=	${WRKSRC}/poppler-glib.pc.in

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
# Build the cairo graphics backend, required by glib.
CONFIGURE_ARGS+=	--enable-cairo-output
# Don't build the splash graphics backend.
CONFIGURE_ARGS+=	--disable-splash-output
# Don't compile poppler qt wrapper.
CONFIGURE_ARGS+=	--disable-poppler-qt
# Don't compile GTK+ test program.
CONFIGURE_ARGS+=	--disable-gtk-test
CONFIGURE_ARGS+=	--disable-utils
CONFIGURE_ARGS+=	--disable-poppler-cpp

BUILDLINK_API_DEPENDS.poppler+=     poppler-${POPPLER_VERS}{,nb*}
.include "../../print/poppler/buildlink3.mk"

.if !empty(PKG_BUILD_OPTIONS.poppler:Mpoppler-cms)
CONFIGURE_ARGS+=	--enable-cms
.else
CONFIGURE_ARGS+=	--disable-cms
.endif

BUILD_DIRS=		goo fofi poppler glib
INSTALL_DIRS=		glib

INSTALLATION_DIRS+=	lib/pkgconfig

post-install:
	${INSTALL_DATA} ${WRKSRC}/poppler-cairo.pc ${DESTDIR}${PREFIX}/lib/pkgconfig
	${INSTALL_DATA} ${WRKSRC}/poppler-glib.pc ${DESTDIR}${PREFIX}/lib/pkgconfig

.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
