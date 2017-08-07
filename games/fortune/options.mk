# $NetBSD: options.mk,v 1.1 2017/08/07 11:10:32 jperkin Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.fortune
PKG_SUPPORTED_OPTIONS=		offensive

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	off

.if !empty(PKG_OPTIONS:Moffensive)
MAKE_ENV+=	OFFENSIVE=1
PLIST.off=	yes
.else
MAKE_ENV+=	OFFENSIVE=0
.endif
