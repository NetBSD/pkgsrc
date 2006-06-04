# $NetBSD: Makefile,v 1.8 2006/06/04 16:26:55 joerg Exp $

MODNAME=		mhash
CATEGORIES+=		security
COMMENT=		PHP extension for the mhash hash algorithms library

CONFLICTS=	php-mhash-[0-9]*

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.mhash}

.include "../../lang/php/ext.mk"
.include "../../security/mhash/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
