# $NetBSD: Makefile,v 1.4 2005/04/11 21:47:17 tv Exp $

MODNAME=		mhash
CATEGORIES+=		security
PKGREVISION=		# empty
COMMENT=		PHP extension for the mhash hash algorithms library


CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.mhash}

.include "../../lang/php/ext.mk"
.include "../../security/mhash/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
