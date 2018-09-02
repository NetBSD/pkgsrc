# $NetBSD: options.mk,v 1.9 2018/09/02 00:52:50 maya Exp $

.include "../../mk/bsd.prefs.mk"

PKG_OPTIONS_VAR=	PKG_OPTIONS.imap-uw
PKG_SUPPORTED_OPTIONS+=	imapuw-cleartextpwd imapuw-whoson inet6 ssl
PKG_SUGGESTED_OPTIONS+=	imapuw-cleartextpwd inet6 ssl
PKG_SUPPORTED_OPTIONS+=	kerberos

.include "../../mk/bsd.options.mk"

###
### Support both IPv6 and IPv4 connections.
###
.if !empty(PKG_OPTIONS:Minet6)
MAKE_FLAGS+=	IP=6
.else
MAKE_FLAGS+=	IP=4
.endif

###
### Support GSSAPI authentication via Kerberos 5.
###
.if !empty(PKG_OPTIONS:Mkerberos)
.  include "../../mk/krb5.buildlink3.mk"
MAKE_ENV+=	KRB5_TYPE=${KRB5_TYPE}
MAKE_ENV+=	EXTRAAUTHENTICATORS=gss
EXTRASPECIALS+=	GSSDIR=${KRB5BASE}
CFLAGS.heimdal=	-DHEIMDAL_KRB5
CFLAGS+=	${CFLAGS.${KRB5_TYPE}}
.endif

###
### Support using WHOSON for authentication.
###
.if !empty(PKG_OPTIONS:Mimapuw-whoson)
.  include "../../net/whoson/buildlink3.mk"
LDFLAGS+=	-lwhoson
CFLAGS+=	-DUSE_WHOSON
.endif

###
### Support SSL/TLS connections.
###
.if !empty(PKG_OPTIONS:Mssl)
.  include "../../security/openssl/buildlink3.mk"
.  if !empty(PKG_OPTIONS:Mimapuw-cleartextpwd)
MAKE_FLAGS+=	SSLTYPE=unix	# plaintext auth
.  else
MAKE_FLAGS+=	SSLTYPE=nopwd	# plaintext auth only over SSL/TLS
.  endif

MESSAGE_SRC+=	${PKGDIR}/MESSAGE.ssl
MESSAGE_SUBST+=	SSLCERTS=${SSLCERTS:Q}
MESSAGE_SUBST+=	SSLKEYS=${SSLKEYS:Q}

EXTRASPECIALS+=	SSLINCLUDE=${SSLBASE:Q}/include
EXTRASPECIALS+=	SSLLIB=${SSLBASE:Q}/lib
EXTRASPECIALS+=	SSLCERTS=${SSLCERTS:Q}
EXTRASPECIALS+=	SSLKEYS=${SSLKEYS:Q}
.else
MAKE_FLAGS+=	SSLTYPE=none	# no SSL/TLS
.endif
