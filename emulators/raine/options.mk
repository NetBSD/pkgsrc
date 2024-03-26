# $NetBSD: options.mk,v 1.1 2024/03/26 14:10:07 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.raine
PKG_SUPPORTED_OPTIONS=		debug

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CFLAGS+=		-DRAINE_DEBUG=1
.endif
