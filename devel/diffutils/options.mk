# $NetBSD: options.mk,v 1.2 2024/05/26 07:05:45 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.diffutils
PKG_SUPPORTED_OPTIONS+=	nls
PKG_SUGGESTED_OPTIONS=	nls

PLIST_VARS+=	nls

.include "../../mk/bsd.options.mk"

# nls
.if !empty(PKG_OPTIONS:Mnls)
.include "../../devel/gettext-lib/buildlink3.mk"
PLIST.nls=	yes
.else
CONFIGURE_ARGS+= --disable-nls
.endif
