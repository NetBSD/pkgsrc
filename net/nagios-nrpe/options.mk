# $NetBSD: options.mk,v 1.7 2019/11/03 11:45:42 rillig Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.nagios-nrpe
PKG_SUPPORTED_OPTIONS=	ssl tcpwrappers nagios-nrpe-args
PKG_SUGGESTED_OPTIONS=	ssl tcpwrappers

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
CONFIGURE_ARGS+=	--enable-command-args
.else
# Upstream's configure enables command args when given
# "--disable-command-args", so (departing from pkgsrc norms) don't
# give the --disable option.
#CONFIGURE_ARGS+=	--disable-command-args
.endif

.if !empty(PKG_OPTIONS:Mtcpwrappers)
.  include "../../security/tcp_wrappers/buildlink3.mk"
.endif
