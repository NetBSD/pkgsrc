# $NetBSD: options.mk,v 1.1 2011/03/11 11:42:35 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libgnome
PKG_SUPPORTED_OPTIONS=	esound

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mesound)
BUILDLINK_API_DEPENDS.esound+=		esound>=0.2.26
.include "../../audio/esound/buildlink3.mk"
BUILDLINK_API_DEPENDS.audiofile+=	libaudiofile>=0.2.3
.include "../../audio/libaudiofile/buildlink3.mk"
.else
CONFIGURE_ARGS+= --disable-esd
.endif
