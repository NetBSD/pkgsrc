$NetBSD: options.mk,v 1.1 2008/01/21 00:43:49 markd Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.arts
PKG_SUPPORTED_OPTIONS=	esound nas jack
PKG_SUGGESTED_OPTIONS=	esound

.include "../../mk/bsd.options.mk"

# ESOUND support
.if !empty(PKG_OPTIONS:Mesound)
.include "../../audio/esound/buildlink3.mk"
.endif

# NAS support
.if !empty(PKG_OPTIONS:Mnas)
.include "../../audio/nas/buildlink3.mk"
.endif

# JACK support
.if !empty(PKG_OPTIONS:Mjack)
.include "../../audio/jack/buildlink3.mk"
.endif
