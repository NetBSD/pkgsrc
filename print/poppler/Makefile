# $NetBSD: Makefile,v 1.57 2012/09/14 12:15:01 drochner Exp $
#

.include "../../print/poppler/Makefile.common"

COMMENT=		PDF rendering library
MAINTAINER=		reed@reedmedia.net

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
# Don't compile GTK+ test program.
CONFIGURE_ARGS+=	--disable-gtk-test
# Don't compile GLib wrapper which also needs gtk2
CONFIGURE_ARGS+=	--disable-poppler-glib
# Don't build and install the tools
CONFIGURE_ARGS+=	--disable-utils
CONFIGURE_ARGS+=	--disable-poppler-cpp

PKG_OPTIONS_VAR=	PKG_OPTIONS.poppler
PKG_SUPPORTED_OPTIONS=	poppler-cms
PKG_SUGGESTED_OPTIONS=	poppler-cms
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpoppler-cms)
CONFIGURE_ARGS+=	--enable-cms
.include "../../graphics/lcms2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-cms
.endif

.include "../../mk/bsd.prefs.mk"

post-install:
	${INSTALL_MAN} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/poppler/
	${INSTALL_MAN} ${WRKSRC}/README-XPDF ${DESTDIR}${PREFIX}/share/doc/poppler/
	${RMDIR} ${DESTDIR}${PREFIX}/include/poppler || ${TRUE}

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
