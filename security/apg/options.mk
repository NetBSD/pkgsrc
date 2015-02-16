# $NetBSD: options.mk,v 1.1 2015/02/16 00:25:45 rodent Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.apg
PKG_SUPPORTED_OPTIONS=	debug libcrack
PKG_SUGGESTED_OPTIONS=	# blank

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CFLAGS+=		-DAPG_DEBUG
.endif

.if !empty(PKG_OPTIONS:Mlibcrack)
.include "../../security/libcrack/buildlink3.mk"
CFLAGS+=		-I${PREFIX}/include/cracklib -DAPG_USE_CRACKLIB
CFLAGS+=		-DCRACKLIB_DICTPATH=\"${PREFIX}/libdata\"
BUILDLINK_TRANSFORM+=	l:crypt:crypt:crack
.endif
