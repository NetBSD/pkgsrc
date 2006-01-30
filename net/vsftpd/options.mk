# $NetBSD: options.mk,v 1.2 2006/01/30 18:07:06 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.vsftpd
PKG_SUPPORTED_OPTIONS=	inet6 ssl tcpwrappers
PKG_SUGGESTED_OPTIONS=	inet6 tcpwrappers

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
BROKEN=		Needs ipv6 option enabled.
.endif

.if !empty(PKG_OPTIONS:Mssl)
.include "../../security/openssl/buildlink3.mk"
SUBST_CLASSES+=		ssl
SUBST_FILES.ssl=	builddefs.h
SUBST_SED.ssl+=		-e 's,undef VSF_BUILD_SSL,define VSF_BUILD_SSL,g'
SUBST_SED.ssl+=		-e 's,/usr/share/ssl/certs/vsftpd.pem,${SSLCERTS}/vsftpd.pem,g'
SUBST_STAGE.ssl=	pre-configure
.endif

.if !empty(PKG_OPTIONS:Mtcpwrappers)
.include "../../security/tcp_wrappers/buildlink3.mk"
SUBST_CLASSES+=			tcpwrappers
SUBST_FILES.tcpwrappers=	builddefs.h
SUBST_SED.tcpwrappers+=		-e 's,undef VSF_BUILD_TCPWRAPPERS,define VSF_BUILD_TCPWRAPPERS,g'
SUBST_STAGE.tcpwrappers=	pre-configure
.endif
