# $NetBSD: options.mk,v 1.1 2025/07/03 15:46:59 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.sox_ng
PKG_SUPPORTED_OPTIONS=	oss

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Moss)
LDFLAGS+=		-lossaudio
.include "../../mk/oss.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-oss
.endif
