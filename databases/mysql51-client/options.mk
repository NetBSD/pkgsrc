# $NetBSD: options.mk,v 1.2 2010/03/04 16:34:23 taca Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mysql5

PKG_SUPPORTED_OPTIONS+=	embedded-server ssl
PKG_SUGGESTED_OPTIONS+=	embedded-server ssl

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
