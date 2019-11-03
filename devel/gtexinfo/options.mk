# $NetBSD: options.mk,v 1.6 2019/11/03 10:39:13 rillig Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.gtexinfo
PKG_SUPPORTED_OPTIONS=		nls
PKG_SUGGESTED_OPTIONS=		# blank
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
