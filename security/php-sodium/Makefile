# $NetBSD: Makefile,v 1.7 2021/01/03 16:06:57 taca Exp $

MODNAME=		sodium
CATEGORIES+=		security
COMMENT=		PHP extension for the sodium crypto algorithms library

CONFIGURE_ARGS+=	--with-${MODNAME}=${BUILDLINK_PREFIX.libsodium}

PHP_VERSIONS_INCOMPATIBLE=	56

.include "../../lang/php/ext.mk"
.include "../../security/libsodium/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
