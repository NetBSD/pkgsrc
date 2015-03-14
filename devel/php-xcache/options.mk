# $NetBSD: options.mk,v 1.1 2015/03/14 18:52:30 rodent Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.php-xcache

PKG_SUPPORTED_OPTIONS=	xcache-constant xcache-optimizer xcache-coverager
PKG_SUPPORTED_OPTIONS+=	xcache-assembler xcache-disassembler xcache-encoder
PKG_SUPPORTED_OPTIONS+=	xcache-decoder
PKG_SUGGESTED_OPTIONS=	xcache-constant xcache-optimizer xcache-coverager

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mxcache-constant)
CONFIGURE_ARGS+=	--enable-xcache-constant
.endif

.if !empty(PKG_OPTIONS:Mxcache-optimizer)
CONFIGURE_ARGS+=	--enable-xcache-optimizer
.endif

.if !empty(PKG_OPTIONS:Mxcache-coverager)
CONFIGURE_ARGS+=	--enable-xcache-coverager
.endif

.if !empty(PKG_OPTIONS:Mxcache-assembler)
CONFIGURE_ARGS+=	--enable-xcache-assembler
.endif

.if !empty(PKG_OPTIONS:Mxcache-disassembler)
CONFIGURE_ARGS+=	--enable-xcache-disassembler
.endif

.if !empty(PKG_OPTIONS:Mxcache-encoder)
CONFIGURE_ARGS+=	--enable-xcache-encoder
.endif

.if !empty(PKG_OPTIONS:Mxcache-decoder)
CONFIGURE_ARGS+=	--enable-xcache-decoder
.endif
