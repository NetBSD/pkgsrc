# $NetBSD: options.mk,v 1.1 2015/02/27 12:11:20 gdt Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.radare2
PKG_SUPPORTED_OPTIONS=		ssl debug
PKG_SUGGESTED_OPTIONS=		debug

.include "../../mk/bsd.options.mk"

# SSL support
.if !empty(PKG_OPTIONS:Mssl)
.  include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-openssl
.endif

.if empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--disable-debugger
.endif
