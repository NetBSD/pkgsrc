# $NetBSD: Makefile,v 1.1.1.1 2001/10/16 05:39:57 jlam Exp $

.include "../php4/Makefile.module"

MODNAME=		imap
CATEGORIES+=		mail
PHP_PKG_VERS=		# empty
COMMENT=		PHP4 extension for IMAP (Internet Mailbox Access Protocol)

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_DIR}
CONFIGURE_ARGS+=	--with-${MODNAME}-ssl=shared,${BUILDLINK_DIR}
CONFIGURE_ENV+=		ac_cv_lib_pam_pam_start=no

LIBS+=			-lssl -lcrypto

.include "../../mail/imap-uw/buildlink.mk"
.include "../../security/openssl/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
