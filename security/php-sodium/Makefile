# $NetBSD: Makefile,v 1.1 2017/11/15 08:58:35 jdolecek Exp $

MODNAME=		sodium
CATEGORIES+=		security
COMMENT=		PHP extension for the sodium crypto algorithms library

CONFIGURE_ARGS+=	--with-${MODNAME}=shared

PHP_VERSIONS_ACCEPTED=	72

.include "../../lang/php/ext.mk"
.include "../../security/libsodium/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
