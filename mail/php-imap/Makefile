# $NetBSD: Makefile,v 1.32 2018/02/16 22:21:25 jdolecek Exp $

MODNAME=		imap
CATEGORIES+=		mail
COMMENT=		PHP extension for IMAP (Internet Mailbox Access Protocol)
PKGREVISION=	1

CONFLICTS=	php-imap-[0-9]*

USE_TOOLS+=		pkg-config

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.imap-uw}
CONFIGURE_ARGS+=	--with-${MODNAME}-linkage

CONFIGURE_ENV+=		ac_cv_lib_pam_pam_start=no

.include "options.mk"
.include "../../mail/imap-uw/buildlink3.mk"
.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
