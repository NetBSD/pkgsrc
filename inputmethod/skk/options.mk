# $NetBSD: options.mk,v 1.5 2008/04/12 22:43:02 jlam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.skk
PKG_SUPPORTED_OPTIONS=	lookup

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		lookup

.if !empty(PKG_OPTIONS:Mlookup)
.include "../../misc/lookup/buildlink3.mk"
PLIST.lookup=		yes
.endif
