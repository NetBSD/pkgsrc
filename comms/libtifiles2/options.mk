# $NetBSD: options.mk,v 1.1 2013/05/26 22:59:42 rodent Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libtifiles2
PKG_SUPPORTED_OPTIONS=	nls
PKG_SUGGESTED_OPTIONS+=	nls
PLIST_VARS+=		nls

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mnls)
PLIST.nls=		yes
.else
CONFIGURE_ARGS+=	--disable-nls
.endif
