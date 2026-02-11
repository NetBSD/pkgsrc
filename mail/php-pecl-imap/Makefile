# $NetBSD: Makefile,v 1.4 2026/02/11 08:29:36 taca Exp $

MODNAME=		imap
PECL_VERSION=		1.0.3
CATEGORIES+=		mail

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		PHP extension for IMAP, including NNTP, POP3
PKGREVISION=		2
LICENSE=		php

PHP_VERSIONS_ACCEPTED=	84 85

USE_TOOLS+=		pkg-config

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.imap-uw}
CONFIGURE_ENV+=		ac_cv_lib_pam_pam_start=no

.include "options.mk"
.include "../../mail/imap-uw/buildlink3.mk"
.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
