# $NetBSD: Makefile,v 1.2 2004/10/31 21:07:14 jdolecek Exp $

MODNAME=		mcrypt
CATEGORIES+=		security
PKGREVISION=		# empty
COMMENT=		PHP extension for the mcrypt crypto algorithms library

USE_BUILDLINK3=		YES

.include "../../lang/php/ext.mk"

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.libmcrypt}

.include "../../security/libmcrypt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
