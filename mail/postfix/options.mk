# $NetBSD: options.mk,v 1.40 2015/09/08 14:03:04 fhajny Exp $

# Global and legacy options

PKG_OPTIONS_VAR=	PKG_OPTIONS.postfix
PKG_SUPPORTED_OPTIONS=	sasl tls eai
PKG_SUGGESTED_OPTIONS=	tls

.include "../../mk/bsd.options.mk"

###
### STARTTLS support
###
.if !empty(PKG_OPTIONS:Mtls)
.  include "../../security/openssl/buildlink3.mk"
CCARGS+=	-DUSE_TLS
AUXLIBS+=	-L${BUILDLINK_PREFIX.openssl}/lib			\
		${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib	\
		-lssl -lcrypto
.else
CCARGS+=	-DNO_TLS
.endif

###
### Cyrus SASL support for SMTP authentication.
### (Dovecot SASL support is built in by default.)
###
PLIST_VARS+=	csasl
.if !empty(PKG_OPTIONS:Msasl)
.  include "../../security/cyrus-sasl/buildlink3.mk"
BUILDLINK_INCDIRS.cyrus-sasl=	include/sasl
SASLLIBDIR=	${PREFIX}/lib/sasl2
PWCHECK_METHOD=	auxprop
CCARGS+=	-DUSE_CYRUS_SASL
AUXLIBS+=	-L${BUILDLINK_PREFIX.cyrus-sasl}/lib			\
		${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.cyrus-sasl}/lib \
		-lsasl2
PLIST.csasl=	yes
MESSAGE_SRC+=	${PKGDIR}/MESSAGE.sasl
MESSAGE_SUBST+=	PKG_SYSCONFDIR=${PKG_SYSCONFDIR}
MESSAGE_SUBST+=	SASLLIBDIR=${SASLLIBDIR}
MAKE_DIRS+=	${SASLLIBDIR}
CONF_FILES+=	${EXAMPLEDIR}/smtpd.conf ${SASLLIBDIR}/smtpd.conf
.else
CCARGS+=	-DDEF_SERVER_SASL_TYPE=\"dovecot\"
.endif

###
### EAI (Email Address Internationalization) support (SMTPUTF8)
###
.if !empty(PKG_OPTIONS:Meai)
.  include "../../textproc/icu/buildlink3.mk"
CCARGS+=	-DHAS_EAI -I${BUILDLINK_PREFIX.icu}/include
AUXLIBS+=	-L${BUILDLINK_PREFIX.icu}/lib -licuuc			\
		${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.icu}/lib
.else
CCARGS+=	-DNO_EAI

post-install:
	cd ${WRKSRC} && ${SETENV} LD_LIBRARY_PATH=${WRKSRC}/lib bin/postconf	\
		-c ${DESTDIR}${EXAMPLEDIR} smtputf8_enable=no
.endif
