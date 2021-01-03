# $NetBSD: Makefile,v 1.6 2021/01/03 15:26:11 taca Exp $

MODNAME=		sodium
CATEGORIES+=		security
COMMENT=		PHP extension for the sodium crypto algorithms library

CONFIGURE_ARGS+=	--with-${MODNAME}=${BUILDLINK_PREFIX.libsodium}

PHP_VERSIONS_ACCEPTED=	73 74

.include "../../lang/php/ext.mk"
.include "../../security/libsodium/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
