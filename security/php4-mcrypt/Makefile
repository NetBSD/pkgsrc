# $NetBSD: Makefile,v 1.10 2003/08/31 19:55:57 jdolecek Exp $

MODNAME=		mcrypt
CATEGORIES+=		security
PKGREVISION=		# empty
COMMENT=		PHP4 extension for the mcrypt crypto algorithms library

USE_BUILDLINK2=		YES

.include "../../www/php4/Makefile.module"

MCRYPT_DIR=		${BUILDLINK_PREFIX.libmcrypt}
CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${MCRYPT_DIR}
CONFIGURE_ENV+=		MCRYPT_DIR="${MCRYPT_DIR}"

.include "../../security/libmcrypt/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
