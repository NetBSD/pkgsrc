# $NetBSD: options.mk,v 1.4 2012/06/02 18:33:32 dholland Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.kmymoney2
PKG_SUPPORTED_OPTIONS=	libofx
PKG_SUGGESTED_OPTIONS=	libofx

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		libofx #sqlite3

.if !empty(PKG_OPTIONS:Mlibofx)
.include "../../finance/libofx/buildlink3.mk"
PLIST.libofx=		yes
.endif
