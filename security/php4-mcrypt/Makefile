# $NetBSD: Makefile,v 1.8 2002/11/05 07:33:19 martti Exp $

MODNAME=		mcrypt
CATEGORIES+=		security
PKGREVISION=		# empty
COMMENT=		PHP4 extension for the mcrypt crypto algorithms library

USE_BUILDLINK2=		YES

.include "../../www/php4/Makefile.module"

MCRYPT_DIR=		${BUILDLINK_PREFIX.libmcrypt22}
CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${MCRYPT_DIR}
CONFIGURE_ENV+=		MCRYPT_DIR="${MCRYPT_DIR}"

.include "../../security/libmcrypt22/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
