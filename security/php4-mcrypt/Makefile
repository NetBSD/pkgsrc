# $NetBSD: Makefile,v 1.9 2003/03/05 09:07:23 wiz Exp $

MODNAME=		mcrypt
CATEGORIES+=		security
PKGREVISION=		1
COMMENT=		PHP4 extension for the mcrypt crypto algorithms library

USE_BUILDLINK2=		YES

.include "../../www/php4/Makefile.module"

MCRYPT_DIR=		${BUILDLINK_PREFIX.libmcrypt}
CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${MCRYPT_DIR}
CONFIGURE_ENV+=		MCRYPT_DIR="${MCRYPT_DIR}"

.include "../../security/libmcrypt/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
