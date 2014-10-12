# $NetBSD: options.mk,v 1.8 2014/10/12 10:25:05 abs Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.vsftpd
PKG_SUPPORTED_OPTIONS=	pam ssl tcpwrappers
PKG_SUGGESTED_OPTIONS=	pam ssl tcpwrappers

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpam)
.include "../../mk/pam.buildlink3.mk"
LIBS+=		-L${PAMBASE}
LIBS+=		${COMPILER_RPATH_FLAG}${PAMBASE}
LIBS+=		-lpam
.else
LIBS.Linux=		-lcrypt
#
SUBST_CLASSES+=		pam
SUBST_FILES.pam=	builddefs.h
SUBST_SED.pam+=		-e 's,define VSF_BUILD_PAM,undef VSF_BUILD_PAM,g'
SUBST_STAGE.pam=	pre-configure
.endif

.if !empty(PKG_OPTIONS:Mssl)
.include "../../security/openssl/buildlink3.mk"
SUBST_CLASSES+=		ssl
SUBST_FILES.ssl=	builddefs.h
SUBST_SED.ssl+=		-e 's,undef VSF_BUILD_SSL,define VSF_BUILD_SSL,g'
SUBST_SED.ssl+=		-e 's,/usr/share/ssl/certs/vsftpd.pem,${SSLCERTS}/vsftpd.pem,g'
SUBST_STAGE.ssl=	pre-configure

LIBS+=		-L${BUILDLINK_PREFIX.openssl}
LIBS+=		${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}
LIBS+=		-lssl -lcrypto
.endif

.if !empty(PKG_OPTIONS:Mtcpwrappers)
.include "../../security/tcp_wrappers/buildlink3.mk"
SUBST_CLASSES+=			tcpwrappers
SUBST_FILES.tcpwrappers=	builddefs.h
SUBST_SED.tcpwrappers+=		-e 's,undef VSF_BUILD_TCPWRAPPERS,define VSF_BUILD_TCPWRAPPERS,g'
SUBST_STAGE.tcpwrappers=	pre-configure

LIBS+=		-L${BUILDLINK_PREFIX.tcp_wrappers}
LIBS+=		${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.tcp_wrappers}
LIBS+=		-lwrap
.endif
