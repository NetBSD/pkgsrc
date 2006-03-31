# $NetBSD: Makefile,v 1.14 2006/03/31 20:37:37 jmmv Exp $
#

.include "../../print/poppler/Makefile.common"

PKGREVISION=		1

COMMENT=		PDF rendering library

USE_TOOLS+=		gmake

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
#PKGCONFIG_OVERRIDE+=	${WRKSRC}/poppler-cairo.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/poppler-splash.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/poppler.pc.in
GNU_CONFIGURE=		yes

INSTALLATION_DIRS+=	share/doc/poppler

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
# TODO: Later add an option to choose Splash versus Cairo backend.
## Don't build the Splash graphics backend.
#CONFIGURE_ARGS+=	--disable-splash-output
# Don't build the cairo graphics backend.
CONFIGURE_ARGS+=	--disable-cairo-output
# Don't compile poppler qt wrapper.
CONFIGURE_ARGS+=	--disable-poppler-qt
# Don't compile GTK+ test program.
CONFIGURE_ARGS+=	--disable-gtk-test
# Don't compile GLib wrapper which also needs gtk2
CONFIGURE_ARGS+=	--disable-poppler-glib

.include "../../mk/bsd.prefs.mk"

.if defined(PAPERSIZE) && ${PAPERSIZE} == "A4"
CONFIGURE_ARGS+=	--enable-a4-paper
.endif

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/include/poppler
	${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/poppler/
	${INSTALL_MAN} ${WRKSRC}/README-XPDF ${PREFIX}/share/doc/poppler/

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
