# $NetBSD: Makefile,v 1.3 2004/11/05 17:11:40 jdolecek Exp $

MODNAME=		mcrypt
CATEGORIES+=		security
PKGREVISION=		# empty
COMMENT=		PHP extension for the mcrypt crypto algorithms library

USE_BUILDLINK3=		YES

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.libmcrypt}

.include "../../lang/php/ext.mk"
.include "../../security/libmcrypt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
