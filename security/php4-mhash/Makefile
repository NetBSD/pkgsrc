# $NetBSD: Makefile,v 1.4 2004/04/24 23:35:15 xtraeme Exp $

MODNAME=		mhash
CATEGORIES+=		security
PKGREVISION=		# empty
COMMENT=		PHP4 extension for the mhash hash algorithms library

USE_BUILDLINK3=		YES

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.mhash}

.include "../../security/mhash/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
