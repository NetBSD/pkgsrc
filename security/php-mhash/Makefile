# $NetBSD: Makefile,v 1.11 2010/03/21 11:20:41 jdolecek Exp $

MODNAME=		mhash
CATEGORIES+=		security
COMMENT=		PHP extension for the mhash hash algorithms library

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=	php-mhash-[0-9]*

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.mhash}

PHP_VERSIONS_ACCEPTED=	52

.include "../../lang/php/ext.mk"
.include "../../security/mhash/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
