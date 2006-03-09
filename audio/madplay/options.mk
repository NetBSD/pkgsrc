# $NetBSD: options.mk,v 1.2 2006/03/09 21:04:41 jlam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.madplay
PKG_SUPPORTED_OPTIONS=	esound oss

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mesound)
.include "../../audio/esound/buildlink3.mk"
.else
CONFIGURE_ARGS+=        --without-esd
.endif

.if !empty(PKG_OPTIONS:Moss)
.include "../../mk/oss.buildlink3.mk"
.endif
