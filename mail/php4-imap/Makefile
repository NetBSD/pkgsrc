# $NetBSD: Makefile,v 1.3 2001/10/16 13:01:57 tron Exp $

.include "../../www/php4/Makefile.module"

MODNAME=		imap
CATEGORIES+=		mail
PHP_PKG_VERS=		# empty
COMMENT=		PHP4 extension for IMAP (Internet Mailbox Access Protocol)

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_DIR}
CONFIGURE_ENV+=		ac_cv_lib_pam_pam_start=no

LIBS+=			-lssl -lcrypto

.include "../../mail/imap-uw/buildlink.mk"
.include "../../security/openssl/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
