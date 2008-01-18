# $NetBSD: Makefile,v 1.13 2008/01/18 05:08:28 tnn Exp $

MODNAME=		imap
PKGREVISION=		2
CATEGORIES+=		mail
COMMENT=		PHP extension for IMAP (Internet Mailbox Access Protocol)

CONFLICTS=	php-imap-[0-9]*

USE_PHP_EXT_PATCHES=	yes

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.imap-uw}
CONFIGURE_ARGS+=	--with-${MODNAME}-ssl=${SSLBASE}
CONFIGURE_ARGS+=	--with-${MODNAME}-linkage

CONFIGURE_ENV+=		ac_cv_lib_pam_pam_start=no

# Imap extension's config.m4 calls m4 macro PHP_SETUP_OPENSSL() which
# expects PHP_ARG_WITH(openssl, ...) being called beforehand so that
# PHP_OPENSSL is set. For a self contained extension build like for
# this package this is not the case of course.

CONFIGURE_ENV+=		PHP_OPENSSL=${SSLBASE:Q}

.include "../../mail/imap-uw/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
