# $NetBSD: options.mk,v 1.1.1.1 2009/02/26 10:50:05 hasso Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.opensc
PKG_SUPPORTED_OPTIONS=	openct pcsc-lite
PKG_SUGGESTED_OPTIONS=	pcsc-lite

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpcsc-lite)
.include "../../security/pcsc-lite/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-pcsc
CONFIGURE_ARGS+=	--with-pcsc-provider=${BUILDLINK_PREFIX.pcsc-lite}/lib/libpcsclite.la
.else
CONFIGURE_ARGS+=	--disable-pcsc
.endif

.if !empty(PKG_OPTIONS:Mopenct)
.include "../../security/openct/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-openct
.else
CONFIGURE_ARGS+=	--disable-openct
.endif
