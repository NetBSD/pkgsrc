# $NetBSD: options.mk,v 1.2 2012/04/30 02:54:28 dholland Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.aqsis
PKG_SUPPORTED_OPTIONS=	qt4
PKG_SUGGESTED_OPTIONS=	qt4

.include "../../mk/bsd.options.mk"

# not actually used, at least for now
PLIST_VARS+=	qt4

.if !empty(PKG_OPTIONS:Mqt4)
.include "../../x11/qt4-libs/buildlink3.mk"
PLIST.qt4=	yes
.endif
