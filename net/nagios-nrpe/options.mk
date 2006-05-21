# $NetBSD: options.mk,v 1.1.1.1 2006/05/21 10:28:40 grant Exp $

PKG_OPTIONS_VAR=        PKG_OPTIONS.nagios-nrpe
PKG_SUPPORTED_OPTIONS=  ssl tcpwrappers
PKG_SUGGESTED_OPTIONS=  tcpwrappers

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mssl)
CONFIGURE_ARGS+=	--enable-ssl
.  include "../../security/openssl/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-ssl
.endif

.if !empty(PKG_OPTIONS:Mtcpwrappers)
.  include "../../security/tcp_wrappers/buildlink3.mk"
.endif
