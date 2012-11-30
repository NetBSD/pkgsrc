# $NetBSD: options.mk,v 1.2 2012/11/30 14:44:34 gdt Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.opensc

# Really this should be an options group; exactly one of openct,
# pcsc-lite, or ctapi must be specified.
PKG_SUPPORTED_OPTIONS=	pcsc-lite openct
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
