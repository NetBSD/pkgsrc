# $NetBSD: Makefile,v 1.5 2005/04/15 22:38:16 kim Exp $

MODNAME=		imap
PKGREVISION=		# empty
CATEGORIES+=		mail
COMMENT=		PHP extension for IMAP (Internet Mailbox Access Protocol)

USE_PHP_EXT_PATCHES=	yes

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.imap-uw}
CONFIGURE_ARGS+=	--with-${MODNAME}-ssl=${SSLBASE}
CONFIGURE_ARGS+=	--with-${MODNAME}-linkage
CONFIGURE_ENV+=		ac_cv_lib_pam_pam_start=no
CONFIGURE_ENV+=		PHP_OPENSSL=${SSLBASE}

LIBS+=			-lssl -lcrypto

.include "../../mail/imap-uw/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
