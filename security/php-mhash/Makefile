# $NetBSD: Makefile,v 1.9 2008/06/12 02:14:45 joerg Exp $

MODNAME=		mhash
CATEGORIES+=		security
COMMENT=		PHP extension for the mhash hash algorithms library

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=	php-mhash-[0-9]*

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.mhash}

.include "../../lang/php/ext.mk"
.include "../../security/mhash/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
