# $NetBSD: Makefile,v 1.6 2006/02/05 23:10:46 joerg Exp $

MODNAME=		mhash
PKGREVISION=		1
CATEGORIES+=		security
COMMENT=		PHP extension for the mhash hash algorithms library


CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.mhash}

.include "../../lang/php/ext.mk"
.include "../../security/mhash/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
