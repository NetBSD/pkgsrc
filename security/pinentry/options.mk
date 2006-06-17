# $NetBSD: options.mk,v 1.1 2006/06/17 13:46:34 rillig Exp $
#

# XXX This usage of bsd.options.mk is wrong and has to be fixed.  The
# package has to be splitted into different packages, such as pinentry-gtk
# and pinentry-qt, so that the frontends can be built on their own and
# can be distributed in different binary packages.

PKG_OPTIONS_VAR=	PKG_OPTIONS.pinentry
PKG_SUPPORTED_OPTIONS=	gtk qt
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgtk)
CONFIGURE_ARGS+=	--enable-pinentry-gtk
PLIST_SUBST+=		USE_GTK=
.  include "../../x11/gtk/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-pinentry-gtk
PLIST_SUBST+=		USE_GTK='@comment '
.endif

.if !empty(PKG_OPTIONS:Mqt)
USE_LANGUAGES+=		c c++
USE_TOOLS+=		gmake
CONFIGURE_ARGS+=	--enable-pinentry-qt
PLIST_SUBST+=		USE_QT=
.  include "../../x11/qt3-libs/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-pinentry-qt
PLIST_SUBST+=		USE_QT='@comment '
.endif
