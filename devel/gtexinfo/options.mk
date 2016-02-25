# $NetBSD: options.mk,v 1.5 2016/02/25 12:12:48 jperkin Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gtexinfo
PKG_SUPPORTED_OPTIONS=	nls
PKG_SUGGESTED_OPTIONS=	# blank
PKG_SUGGESTED_OPTIONS.NetBSD+=	nls

PKG_OPTIONS_LEGACY_VARS=	TEXINFO_LOCALE

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mnls)
USE_PKGLOCALEDIR=	yes
PLIST_SRC+=		${PKGDIR}/PLIST.locale
.  include "../../devel/gettext-lib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-nls
.endif
