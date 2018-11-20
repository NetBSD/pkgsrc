# $NetBSD: Makefile,v 1.37 2018/11/20 13:20:42 leot Exp $

.include "../../graphics/cairo/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-gobject-/}
PKGREVISION=	3

BUILD_DIRS=	util/cairo-gobject
INSTALL_DIRS=	util/cairo-gobject

INSTALLATION_DIRS+=	lib/pkgconfig

.include "../../mk/bsd.prefs.mk"

post-install:
	${INSTALL_DATA} ${WRKSRC}/src/cairo-gobject.pc \
		${DESTDIR}${PREFIX}/lib/pkgconfig

.include "../../graphics/cairo/buildlink3.mk"
###
### X11 and XCB support (XCB implies X11)
###
### This matches the logic in ../../graphics/cairo/options.mk
###
.if !empty(PKG_BUILD_OPTIONS.cairo:Mx11) || !empty(PKG_BUILD_OPTIONS.cairo:Mxcb)
CONFIGURE_ARGS+=	--enable-xlib
CONFIGURE_ARGS+=	--enable-xlib-xrender
.  if !empty(PKG_BUILD_OPTIONS.cairo:Mxcb)
CONFIGURE_ARGS+=	--enable-xcb
.  else
CONFIGURE_ARGS+=	--disable-xcb
.  endif
.else
CONFIGURE_ARGS+=	--disable-xlib
CONFIGURE_ARGS+=	--disable-xlib-xrender
CONFIGURE_ARGS+=	--disable-xcb
.endif

BUILDLINK_ABI_DEPENDS.glib2+=	glib2>=2.14.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
