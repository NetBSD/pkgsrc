# $NetBSD: Makefile,v 1.6 2002/02/28 06:18:03 jlam Exp $

MODNAME=		imap
CATEGORIES+=		mail
PKGREVISION=		# empty
COMMENT=		PHP4 extension for IMAP (Internet Mailbox Access Protocol)

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_DIR}
CONFIGURE_ARGS+=	--with-${MODNAME}-ssl=${BUILDLINK_DIR}
CONFIGURE_ENV+=		ac_cv_lib_pam_pam_start=no

LIBS+=			-lssl -lcrypto

.include "../../mail/imap-uw/buildlink.mk"
.include "../../security/openssl/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
