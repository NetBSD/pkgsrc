# $NetBSD: options.mk,v 1.1 2026/06/29 15:27:44 jnemeth Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.zork
PKG_OPTIONS_REQUIRED_GROUPS=	z-machine
PKG_OPTIONS_GROUP.z-machine=	frotz xzip zoom
PKG_SUGGESTED_OPTIONS=		frotz

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mfrotz)
DEPENDS+=	frotz-[0-9]*:../../games/frotz
.endif

.if !empty(PKG_OPTIONS:Mxzip)
DEPENDS+=	xzip-[0-9]*:../../games/xzip
.endif

.if !empty(PKG_OPTIONS:Mzoom)
DEPENDS+=	zoom-[0-9]*:../../games/zoom
.endif
