# $NetBSD: options.mk,v 1.4 2007/10/29 13:25:26 uebayasi Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.skk
PKG_SUPPORTED_OPTIONS=	lookup

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlookup)
.include "../../misc/lookup/buildlink3.mk"
PLIST_SUBST+=	FOR_LOOKUP=""
.else
PLIST_SUBST+=	FOR_LOOKUP="@comment "
.endif
