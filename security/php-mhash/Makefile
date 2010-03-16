# $NetBSD: Makefile,v 1.10 2010/03/16 11:56:22 taca Exp $

MODNAME=		mhash
CATEGORIES+=		security
COMMENT=		PHP extension for the mhash hash algorithms library

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=	php-mhash-[0-9]*

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.mhash}

PHP_VERSION_REQD=	5

.include "../../lang/php/ext.mk"
.include "../../security/mhash/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
