# $NetBSD: options.mk,v 1.2 2008/02/29 13:31:20 gdt Exp $

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
