# $NetBSD: options.mk,v 1.5 2019/08/16 13:08:58 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libsoup
PKG_SUPPORTED_OPTIONS=	gssapi
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgssapi)
.  include "../../mk/krb5.buildlink3.mk"
.endif
