# $NetBSD: Makefile,v 1.10 2006/11/13 21:00:39 drochner Exp $
#

.include "../../print/poppler/Makefile.common"

PKGNAME=		poppler-glib-${POPPLER_VERS}
PKGREVISION=		1

COMMENT=		PDF rendering library (GLib wrapper)

CONFLICTS+=		poppler<0.4.5nb1

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake
PKGCONFIG_OVERRIDE+=    ${WRKSRC}/poppler-glib.pc.in

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
# Build the cairo graphics backend, required by glib.
CONFIGURE_ARGS+=	--enable-cairo-output
# Don't build the splash graphics backend.
CONFIGURE_ARGS+=	--disable-splash-output
# Don't compile poppler qt wrapper.
CONFIGURE_ARGS+=	--disable-poppler-qt
# Don't compile GTK+ test program.
CONFIGURE_ARGS+=	--disable-gtk-test

BUILD_DIRS=		${WRKSRC}/goo ${WRKSRC}/fofi ${WRKSRC}/poppler \
			${WRKSRC}/glib
INSTALL_DIRS=		${WRKSRC}/glib

post-install:
	${INSTALL_DATA} ${WRKSRC}/poppler-cairo.pc ${PREFIX}/lib/pkgconfig
	${INSTALL_DATA} ${WRKSRC}/poppler-glib.pc ${PREFIX}/lib/pkgconfig

.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
BUILDLINK_API_DEPENDS.poppler+=     poppler>=${POPPLER_VERS}
.include "../../print/poppler/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
