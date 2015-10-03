# $NetBSD: options.mk,v 1.3 2015/10/03 14:57:10 tnn Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.xz
PKG_SUPPORTED_OPTIONS=	nls
PKG_SUGGESTED_OPTIONS=	nls

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		nls

.if !empty(PKG_OPTIONS:Mnls)
PLIST.nls=		yes
CONFIGURE_ARGS+=	--enable-nls
.include "../../devel/gettext-lib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-nls
.endif
