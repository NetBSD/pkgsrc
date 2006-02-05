# $NetBSD: Makefile,v 1.6 2006/02/05 23:10:46 joerg Exp $

MODNAME=		mcrypt
PKGREVISION=		1
CATEGORIES+=		security
COMMENT=		PHP extension for the mcrypt crypto algorithms library


CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.libmcrypt}

.include "../../lang/php/ext.mk"
.include "../../security/libmcrypt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
