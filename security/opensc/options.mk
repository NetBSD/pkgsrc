# $NetBSD: options.mk,v 1.3 2012/12/03 20:23:15 gdt Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.opensc

# Arguably these should be selectable individually, but upstream requires
# that exactly one be chosen.
PKG_OPTIONS_REQUIRED_GROUPS=	cardreader
PKG_OPTIONS_GROUP.cardreader=	pcsc-lite openct
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
