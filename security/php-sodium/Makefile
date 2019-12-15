# $NetBSD: Makefile,v 1.5 2019/12/15 18:02:30 taca Exp $

MODNAME=		sodium
CATEGORIES+=		security
COMMENT=		PHP extension for the sodium crypto algorithms library

CONFIGURE_ARGS+=	--with-${MODNAME}=${BUILDLINK_PREFIX.libsodium}

PHP_VERSIONS_ACCEPTED=	72 73 74

.include "../../lang/php/ext.mk"
.include "../../security/libsodium/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
