# $NetBSD: Makefile,v 1.3 2002/11/05 07:33:19 martti Exp $

MODNAME=		mhash
CATEGORIES+=		security
PKGREVISION=		# empty
COMMENT=		PHP4 extension for the mhash hash algorithms library

USE_BUILDLINK2=		YES

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.mhash}

.include "../../security/mhash/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
