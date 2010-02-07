# $NetBSD: options.mk,v 1.6 2010/02/07 15:36:58 drochner Exp $
#

# XXX This usage of bsd.options.mk is incorrect.  The package should
# to be split into three packages
#   pinentry-curses
#   pinentry-gtk
#   pinentry-qt

PKG_OPTIONS_VAR=	PKG_OPTIONS.pinentry
PKG_SUPPORTED_OPTIONS=	gtk gtk2 qt
.include "../../mk/bsd.options.mk"

CONFIGURE_ARGS+=	--disable-pinentry-gtk
.if !empty(PKG_OPTIONS:Mgtk)
DEPENDS+=		pinentry-gtk-[0-9]*:../../security/pinentry-gtk
PINENTRY_DEFAULT=	gtk
.endif

CONFIGURE_ARGS+=	--disable-pinentry-gtk2
.if !empty(PKG_OPTIONS:Mgtk2)
DEPENDS+=		pinentry-gtk2-[0-9]*:../../security/pinentry-gtk2
PINENTRY_DEFAULT=	gtk2
.endif

CONFIGURE_ARGS+=	--disable-pinentry-qt
.if !empty(PKG_OPTIONS:Mqt)
DEPENDS+=		pinentry-qt-[0-9]*:../../security/pinentry-qt
PINENTRY_DEFAULT=	qt
.endif
