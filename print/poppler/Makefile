# $NetBSD: Makefile,v 1.27 2008/04/29 19:23:34 drochner Exp $
#

.include "../../print/poppler/Makefile.common"

COMMENT=		PDF rendering library

USE_TOOLS+=		gmake

#PKGCONFIG_OVERRIDE+=	${WRKSRC}/poppler-cairo.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/poppler-splash.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/poppler.pc.in
GNU_CONFIGURE=		yes

INSTALLATION_DIRS+=	include/poppler share/doc/poppler

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
# TODO: Later add an option to choose Splash versus Cairo backend.
# Build the Splash graphics backend.
CONFIGURE_ARGS+=	--enable-splash-output
# Don't build the cairo graphics backend.
CONFIGURE_ARGS+=	--disable-cairo-output
# Don't compile poppler qt wrapper.
CONFIGURE_ARGS+=	--disable-poppler-qt
# Don't compile GTK+ test program.
CONFIGURE_ARGS+=	--disable-gtk-test
# Don't compile GLib wrapper which also needs gtk2
CONFIGURE_ARGS+=	--disable-poppler-glib
# Don't build and install the tools
CONFIGURE_ARGS+=	--disable-utils

.include "../../mk/bsd.prefs.mk"

.if defined(PAPERSIZE) && ${PAPERSIZE} == "A4"
CONFIGURE_ARGS+=	--enable-a4-paper
.endif

post-install:
	${INSTALL_MAN} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/poppler/
	${INSTALL_MAN} ${WRKSRC}/README-XPDF ${DESTDIR}${PREFIX}/share/doc/poppler/

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
