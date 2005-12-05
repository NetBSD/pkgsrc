# $NetBSD: Makefile,v 1.5 2005/12/05 20:50:58 rillig Exp $

MODNAME=		mcrypt
CATEGORIES+=		security
COMMENT=		PHP extension for the mcrypt crypto algorithms library


CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.libmcrypt}

.include "../../lang/php/ext.mk"
.include "../../security/libmcrypt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
