# $NetBSD: Makefile,v 1.11 2003/09/01 16:28:51 jdolecek Exp $

MODNAME=		mcrypt
CATEGORIES+=		security
PKGREVISION=		# empty
COMMENT=		PHP4 extension for the mcrypt crypto algorithms library

USE_BUILDLINK2=		YES

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.libmcrypt}

.include "../../security/libmcrypt/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
