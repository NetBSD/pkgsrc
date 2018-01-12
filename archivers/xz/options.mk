# $NetBSD: options.mk,v 1.5 2018/01/12 11:35:28 jperkin Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.xz
PKG_SUPPORTED_OPTIONS=	nls

# Only add nls as a default option if msgfmt is builtin, otherwise there
# are circular dependency issues with xz -> gettext-tools -> xz.
.include "../../mk/bsd.prefs.mk"
.if exists(${TOOLS_PLATFORM.msgfmt})
PKG_SUGGESTED_OPTIONS=	nls
.endif

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		nls

.if !empty(PKG_OPTIONS:Mnls)
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		msgfmt
PLIST.nls=		yes
CONFIGURE_ARGS+=	--enable-nls
.include "../../devel/gettext-lib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-nls
.endif
