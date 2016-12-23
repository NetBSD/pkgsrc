# $NetBSD: Makefile,v 1.12 2016/12/23 23:01:13 joerg Exp $

MODNAME=		mcrypt
CATEGORIES+=		security
COMMENT=		PHP extension for the mcrypt crypto algorithms library

CONFLICTS=		php-mcrypt-[0-9]*

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.libmcrypt}

# mcrypt is deprecated and removed in 7.1.x
PHP_VERSIONS_ACCEPTED=	56 70

.include "../../lang/php/ext.mk"
.include "../../security/libmcrypt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
