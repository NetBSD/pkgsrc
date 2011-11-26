# $NetBSD: options.mk,v 1.1 2011/11/26 19:01:15 hans Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gmake
PKG_SUPPORTED_OPTIONS=	nls
PKG_SUGGESTED_OPTIONS=	
.if ${OPSYS} == "NetBSD"
PKG_SUGGESTED_OPTIONS+=	nls
.endif

PKG_OPTIONS_LEGACY_VARS=	GMAKE_LOCALE

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mnls)
USE_PKGLOCALEDIR=		yes
PLIST_SRC+=			${PKGDIR}/PLIST.locale
USE_TOOLS+=			msgfmt
.  include "../../devel/gettext-lib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-libintl-prefix
CONFIGURE_ARGS+=	--without-libiconv-prefix
CONFIGURE_ARGS+=	--disable-nls
.endif
