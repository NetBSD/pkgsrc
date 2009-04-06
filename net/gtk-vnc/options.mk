# $NetBSD: options.mk,v 1.1.1.1 2009/04/06 10:17:32 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gtk-vnc
PKG_SUPPORTED_OPTIONS=	python firefox

.include "../../mk/bsd.options.mk"

PLIST_VARS=	python
.if !empty(PKG_OPTIONS:Mpython)
.include "../../lang/python/extension.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
USE_TOOLS+=	gmake
PLIST.python=	yes
.else
CONFIGURE_ARGS+=	--with-python=no
.endif

PLIST_VARS+=	firefox
.if !empty(PKG_OPTIONS:Mfirefox)
.include "../../devel/nspr/buildlink3.mk"
.include "../../www/firefox/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-plugin=yes
PLIST.firefox=	yes
.endif
