# $NetBSD: options.mk,v 1.3 2010/03/21 14:40:15 taca Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mysql5

PKG_SUPPORTED_OPTIONS+=	embedded-server mysqlmanager ndb-cluster pstack ssl
PKG_SUGGESTED_OPTIONS+=	embedded-server mysqlmanager ndb-cluster pstack ssl

.include "../../mk/bsd.options.mk"

###
### Enable OpenSSL support
###
.if !empty(PKG_OPTIONS:Mssl)
.	include "../../security/openssl/buildlink3.mk"
. if ${OPSYS} == "SunOS"
CHECK_BUILTIN.openssl:=yes
.  include "../../security/openssl/builtin.mk"
CHECK_BUILTIN.openssl:=no
.  if ${USE_BUILTIN.openssl} == "yes"
CONFIGURE_ARGS+=	--with-ssl=yes
.  endif
. else
CONFIGURE_ARGS+=	--with-ssl=yes
. endif
.else
CONFIGURE_ARGS+=	--without-ssl
.endif
