# $NetBSD: options.mk,v 1.2 2013/04/08 11:17:11 rodent Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gtexinfo
PKG_SUPPORTED_OPTIONS=	nls
PKG_SUGGESTED_OPTIONS=	# blank
.if ${OPSYS} == "NetBSD"
PKG_SUGGESTED_OPTIONS+=	nls
.endif

PKG_OPTIONS_LEGACY_VARS=	TEXINFO_LOCALE

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mnls)
USE_PKGLOCALEDIR=	yes
PLIST_SRC+=		${PKGDIR}/PLIST.locale
.  include "../../devel/gettext-lib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-nls
.endif
