# $NetBSD: Makefile,v 1.12 2004/04/24 23:35:15 xtraeme Exp $

MODNAME=		mcrypt
CATEGORIES+=		security
PKGREVISION=		# empty
COMMENT=		PHP4 extension for the mcrypt crypto algorithms library

USE_BUILDLINK3=		YES

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.libmcrypt}

.include "../../security/libmcrypt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
