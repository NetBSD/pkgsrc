# $NetBSD: options.mk,v 1.7 2026/10/04 08:41:22 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.gtexinfo
PKG_SUPPORTED_OPTIONS=		nls
PKG_SUGGESTED_OPTIONS=		# blank

.include "../../mk/bsd.options.mk"

# as of 7.3: does not work on NetBSD because it
# leads to conflicting macro definitions
.if !empty(PKG_OPTIONS:Mnls)
USE_PKGLOCALEDIR=	yes
PLIST_SRC+=		${PKGDIR}/PLIST.locale
.  include "../../devel/gettext-lib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-nls
.endif
