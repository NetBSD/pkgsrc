# $NetBSD: options.mk,v 1.2 2008/04/12 22:42:59 jlam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.allegro
PKG_SUPPORTED_OPTIONS=	esound

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		esound

.if !empty(PKG_OPTIONS:Mesound)
CONFIGURE_ARGS+=	--enable-esddigi
PLIST.esound=		yes
.include "../../audio/esound/buildlink3.mk"
.endif
