# $NetBSD: options.mk,v 1.3 2010/01/21 17:05:59 drochner Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gtk-vnc
PKG_SUPPORTED_OPTIONS=	python plugin vnc-sasl
PKG_SUGGESTED_OPTIONS=	vnc-sasl

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

PLIST_VARS+=	plugin
.if !empty(PKG_OPTIONS:Mplugin)
.include "../../devel/xulrunner/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-plugin=yes
PLIST.plugin=	yes
.endif

.if !empty(PKG_OPTIONS:Mvnc-sasl)
.include "../../security/cyrus-sasl/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-sasl
.endif
