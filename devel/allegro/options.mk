# $NetBSD: options.mk,v 1.1 2005/06/01 14:29:58 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.allegro
PKG_SUPPORTED_OPTIONS=	esound

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mesound)
CONFIGURE_ARGS+=	--enable-esddigi
.include "../../audio/esound/buildlink3.mk"
PLIST_SUBST+=		ESOUND=""
.else
PLIST_SUBST+=		ESOUND="@comment "
.endif
