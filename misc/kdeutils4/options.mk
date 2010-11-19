# $NetBSD: options.mk,v 1.1 2010/11/19 08:29:30 mrg Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.kdeutils
PKG_SUPPORTED_OPTIONS=	cups
PKG_SUGGESTED_OPTIONS=	cups

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		cups
.if !empty(PKG_OPTIONS:Mcups)
.include "../../print/py-cups/buildlink3.mk"
PLIST.cups=		yes
.endif
