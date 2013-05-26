# $NetBSD: options.mk,v 1.1 2013/05/26 23:06:05 rodent Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gfm
PKG_SUPPORTED_OPTIONS=	nls
PKG_SUGGESTED_OPTIONS+=	nls
PLIST_VARS+=		nls

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mnls)
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
PLIST.nls=		yes
.else
CONFIGURE_ARGS+=	--disable-nls
.endif
