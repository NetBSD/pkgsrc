# $NetBSD: Makefile,v 1.14 2004/03/26 02:27:44 wiz Exp $

MODNAME=		imap
PKGREVISION=		1
CATEGORIES+=		mail
COMMENT=		PHP4 extension for IMAP (Internet Mailbox Access Protocol)

USE_BUILDLINK2=		YES
DISTINFO_FILE=		${.CURDIR}/distinfo

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.imap-uw}
CONFIGURE_ARGS+=	--with-${MODNAME}-ssl=${SSLBASE}
CONFIGURE_ARGS+=	--with-${MODNAME}-linkage
CONFIGURE_ENV+=		ac_cv_lib_pam_pam_start=no

LIBS+=			-lssl -lcrypto

.include "../../mail/imap-uw/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
