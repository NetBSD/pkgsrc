# $NetBSD: options.mk,v 1.1 2007/01/25 07:35:30 epg Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.subversion
PKG_SUPPORTED_OPTIONS=	apache22 apr1

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mapache22)
PKG_OPTIONS+=		apr1
.elif !empty(PKG_OPTIONS:Mapr1)
PKG_OPTIONS+=		apache22
.endif
