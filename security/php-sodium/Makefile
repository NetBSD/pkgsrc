# $NetBSD: Makefile,v 1.4 2018/12/15 17:14:43 taca Exp $

MODNAME=		sodium
CATEGORIES+=		security
COMMENT=		PHP extension for the sodium crypto algorithms library

CONFIGURE_ARGS+=	--with-${MODNAME}=${BUILDLINK_PREFIX.libsodium}

PHP_VERSIONS_ACCEPTED=	72 73

.include "../../lang/php/ext.mk"
.include "../../security/libsodium/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
