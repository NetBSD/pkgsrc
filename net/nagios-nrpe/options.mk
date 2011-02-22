# $NetBSD: options.mk,v 1.4 2011/02/22 15:09:07 gdt Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.nagios-nrpe
PKG_SUPPORTED_OPTIONS=	ssl tcpwrappers nagios-nrpe-args
PKG_SUGGESTED_OPTIONS=	tcpwrappers

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mssl)
CONFIGURE_ARGS+=	--enable-ssl
.  include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-ssl=${SSLBASE}
CONFIGURE_ARGS+=	--with-ssl-lib=${SSLBASE}/lib
CONFIGURE_ARGS+=	--with-ssl-inc=${SSLBASE}/include
.else
CONFIGURE_ARGS+=	--disable-ssl
.endif

.if !empty(PKG_OPTIONS:Mnagios-nrpe-args)
CONFIGURE_ARGS+=       --enable-command-args
.else
CONFIGURE_ARGS+=       --disable-command-args
.endif

.if !empty(PKG_OPTIONS:Mtcpwrappers)
.  include "../../security/tcp_wrappers/buildlink3.mk"
.endif
