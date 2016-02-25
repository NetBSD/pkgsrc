# $NetBSD: Makefile,v 1.29 2016/02/25 15:00:51 jperkin Exp $

MODNAME=		imap
CATEGORIES+=		mail
COMMENT=		PHP extension for IMAP (Internet Mailbox Access Protocol)

CONFLICTS=	php-imap-[0-9]*

USE_PHP_EXT_PATCHES=	yes

USE_TOOLS+=		pkg-config

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.imap-uw}
CONFIGURE_ARGS+=	--with-${MODNAME}-linkage

CONFIGURE_ENV+=		ac_cv_lib_pam_pam_start=no

# Imap extension's config.m4 calls m4 macro PHP_SETUP_OPENSSL() which
# expects PHP_ARG_WITH(openssl, ...) being called beforehand so that
# PHP_OPENSSL is set. For a self contained extension build like for
# this package this is not the case of course.
CONFIGURE_ENV.SunOS+=	PHP_OPENSSL=yes
CONFIGURE_ENV.*+=	PHP_OPENSSL=${SSLBASE:Q}
CONFIGURE_ARGS.SunOS+=	--with-${MODNAME}-ssl=yes
CONFIGURE_ARGS.*+=	--with-${MODNAME}-ssl=${SSLBASE}

.include "../../mail/imap-uw/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
