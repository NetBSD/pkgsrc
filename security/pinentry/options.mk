# $NetBSD: options.mk,v 1.5 2008/04/12 22:43:12 jlam Exp $
#

# XXX This usage of bsd.options.mk is incorrect.  The package should
# to be split into three packages
#   pinentry-curses
#   pinentry-gtk
#   pinentry-qt

PKG_OPTIONS_VAR=	PKG_OPTIONS.pinentry
PKG_SUPPORTED_OPTIONS=	gtk gtk2 qt
.include "../../mk/bsd.options.mk"

PLIST_VARS+=		${PKG_SUPPORTED_OPTIONS}

.if !empty(PKG_OPTIONS:Mgtk)
CONFIGURE_ARGS+=	--enable-pinentry-gtk
PLIST.gtk=		yes
.  include "../../x11/gtk/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-pinentry-gtk
.endif

.if !empty(PKG_OPTIONS:Mgtk2)
CONFIGURE_ARGS+=	--enable-pinentry-gtk2
PLIST.gtk2=		yes
.  include "../../x11/gtk2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-pinentry-gtk2
.endif

.if !empty(PKG_OPTIONS:Mqt)
USE_LANGUAGES+=		c c++
USE_TOOLS+=		gmake
CONFIGURE_ARGS+=	--enable-pinentry-qt
CONFIGURE_ARGS+=	--with-qt-dir=${QTDIR:Q}
CONFIGURE_ARGS+=	--with-qt-includes=${BUILDLINK_PREFIX.qt3-libs}/qt3/include
CONFIGURE_ARGS+=	--with-qt-libraries=${BUILDLINK_PREFIX.qt3-libs}/qt3/lib
PLIST.qt=		yes
.  include "../../x11/qt3-libs/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-pinentry-qt
.endif
