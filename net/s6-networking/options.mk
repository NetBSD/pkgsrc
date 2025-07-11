# $NetBSD: options.mk,v 1.10 2025/07/11 21:16:20 schmonz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.s6-networking
PKG_OPTIONS_OPTIONAL_GROUPS=	tls
PKG_OPTIONS_GROUP.tls=		bearssl libressl openssl
PKG_SUPPORTED_OPTIONS+=		execline
PKG_SUGGESTED_OPTIONS+=		execline openssl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mexecline)
DEPENDS+=		execline-[0-9]*:../../lang/execline
.  include "../../lang/execline/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-execline
.else
CONFIGURE_ARGS+=	--disable-execline
.endif

PLIST_VARS=		tls bearssl libtls

.if !empty(PKG_OPTIONS:Mbearssl)
PLIST.tls=		yes
PLIST.bearssl=		yes
.  include "../../security/bearssl/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-ssl=bearssl
.endif

# XXX libtls-bearssl

.if !empty(PKG_OPTIONS:Mlibressl)
PLIST.tls=		yes
PLIST.libtls=		yes
BUILDLINK_API_DEPENDS.libressl+=	libressl>=4.1.0
.  include "../../security/libressl/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-ssl=libtls
CONFIGURE_ARGS+=	--with-ssl-path=${PREFIX:Q}/libressl
.endif

.if !empty(PKG_OPTIONS:Mopenssl)
PLIST.tls=		yes
PLIST.libtls=		yes
BUILDLINK_API_DEPENDS.libretls+=	libretls>=3.8.1
.  include "../../security/libretls/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-ssl=libtls
.endif

.if !empty(PLIST.tls) && ${PLIST.tls} == "yes"
PKG_USERS_VARS+=	UCSPI_SSL_USER
PKG_GROUPS_VARS+=	UCSPI_SSL_GROUP
PKG_GROUPS+=		${UCSPI_SSL_GROUP}
PKG_USERS+=		${UCSPI_SSL_USER}:${UCSPI_SSL_GROUP}
.endif
