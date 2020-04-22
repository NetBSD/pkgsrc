# $NetBSD: options.mk,v 1.5 2020/04/22 05:01:51 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.balsa
PKG_SUPPORTED_OPTIONS=	compface ldap

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mcompface)
CONFIGURE_ARGS+=	--with-compface
.  include "../../graphics/compface/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mldap)
CONFIGURE_ARGS+=	--with-ldap
.  include "../../databases/openldap-client/buildlink3.mk"
.endif
