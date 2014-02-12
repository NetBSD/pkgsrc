# $NetBSD: Makefile,v 1.27 2014/02/12 23:18:09 tron Exp $

MODNAME=		imap
PKGREVISION=		1
CATEGORIES+=		mail
COMMENT=		PHP extension for IMAP (Internet Mailbox Access Protocol)

CONFLICTS=	php-imap-[0-9]*

USE_PHP_EXT_PATCHES=	yes

USE_TOOLS+=		pkg-config

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.imap-uw}
CONFIGURE_ARGS+=	--with-${MODNAME}-linkage

.if ${OPSYS} == "SunOS"
CONFIGURE_ARGS+=	--with-${MODNAME}-ssl=yes
.else
CONFIGURE_ARGS+=	--with-${MODNAME}-ssl=${SSLBASE}
.endif

CONFIGURE_ENV+=		ac_cv_lib_pam_pam_start=no

# Imap extension's config.m4 calls m4 macro PHP_SETUP_OPENSSL() which
# expects PHP_ARG_WITH(openssl, ...) being called beforehand so that
# PHP_OPENSSL is set. For a self contained extension build like for
# this package this is not the case of course.

.if ${OPSYS} == "SunOS"
CONFIGURE_ENV+=		PHP_OPENSSL=yes
.else
CONFIGURE_ENV+=		PHP_OPENSSL=${SSLBASE:Q}
.endif

.include "../../mail/imap-uw/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
