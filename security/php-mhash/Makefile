# $NetBSD: Makefile,v 1.5 2005/12/05 20:50:58 rillig Exp $

MODNAME=		mhash
CATEGORIES+=		security
COMMENT=		PHP extension for the mhash hash algorithms library


CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.mhash}

.include "../../lang/php/ext.mk"
.include "../../security/mhash/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
