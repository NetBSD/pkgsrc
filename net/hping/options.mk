# $NetBSD: options.mk,v 1.1 2006/03/30 13:51:28 salo Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.hping
PKG_SUPPORTED_OPTIONS=	hping-suid

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mhping-suid)
BINOWN=			root
BINMODE=		4511
.endif
