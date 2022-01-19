# $NetBSD: options.mk,v 1.3 2022/01/19 20:01:18 kim Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.rsync

PKG_SUPPORTED_OPTIONS=	acl
PKG_SUGGESTED_OPTIONS=	acl

.include "../../mk/bsd.options.mk"

.if empty(PKG_OPTIONS:Macl)
CONFIGURE_ARGS+=	--disable-acl-support
.endif
