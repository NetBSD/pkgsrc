# $NetBSD: options.mk,v 1.1 2018/02/16 22:22:58 jdolecek Exp $

.include "../../mk/bsd.prefs.mk"

PKG_OPTIONS_VAR=	PKG_OPTIONS.imap-uw
PKG_SUPPORTED_OPTIONS+=	ssl kerberos
PKG_SUGGESTED_OPTIONS+=	ssl

.include "../../mk/bsd.options.mk"

###
### Support GSSAPI authentication via Kerberos 5.
###
.if !empty(PKG_OPTIONS:Mkerberos)
.  include "../../mk/krb5.buildlink3.mk"
CONFIGURE_ARGS+=	--with-kerberos
.endif

###
### Support SSL/TLS connections.
###
.if !empty(PKG_OPTIONS:Mssl)
.  include "../../security/openssl/buildlink3.mk"

# Imap extension's config.m4 calls m4 macro PHP_SETUP_OPENSSL() which
# expects PHP_ARG_WITH(openssl, ...) being called beforehand so that
# PHP_OPENSSL is set. For a self contained extension build like for
# this package this is not the case of course.
CONFIGURE_ENV.SunOS+=	PHP_OPENSSL=yes
CONFIGURE_ENV.*+=	PHP_OPENSSL=${SSLBASE:Q}
CONFIGURE_ARGS.SunOS+=	--with-${MODNAME}-ssl=yes
CONFIGURE_ARGS.*+=	--with-${MODNAME}-ssl=${SSLBASE}

.endif
