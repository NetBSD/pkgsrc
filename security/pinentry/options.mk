# $NetBSD: options.mk,v 1.4 2006/10/11 18:53:38 shannonjr Exp $
#

# XXX This usage of bsd.options.mk is incorrect.  The package should
# to be split into three packages
#   pinentry-curses
#   pinentry-gtk
#   pinentry-qt

PKG_OPTIONS_VAR=	PKG_OPTIONS.pinentry
PKG_SUPPORTED_OPTIONS=	gtk gtk2 qt
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgtk)
CONFIGURE_ARGS+=	--enable-pinentry-gtk
PLIST_SUBST+=		USE_GTK=
.  include "../../x11/gtk/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-pinentry-gtk
PLIST_SUBST+=		USE_GTK='@comment '
.endif

.if !empty(PKG_OPTIONS:Mgtk2)
CONFIGURE_ARGS+=	--enable-pinentry-gtk2
PLIST_SUBST+=		USE_GTK2=
.  include "../../x11/gtk2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-pinentry-gtk2
PLIST_SUBST+=		USE_GTK2='@comment '
.endif

.if !empty(PKG_OPTIONS:Mqt)
USE_LANGUAGES+=		c c++
USE_TOOLS+=		gmake
CONFIGURE_ARGS+=	--enable-pinentry-qt
CONFIGURE_ARGS+=	--with-qt-dir=${QTDIR:Q}
CONFIGURE_ARGS+=	--with-qt-includes=${BUILDLINK_PREFIX.qt3-libs}/qt3/include
CONFIGURE_ARGS+=	--with-qt-libraries=${BUILDLINK_PREFIX.qt3-libs}/qt3/lib
PLIST_SUBST+=		USE_QT=
.  include "../../x11/qt3-libs/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-pinentry-qt
PLIST_SUBST+=		USE_QT='@comment '
.endif
