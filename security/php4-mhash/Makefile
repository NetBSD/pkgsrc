# $NetBSD: Makefile,v 1.2 2002/10/05 12:40:46 wiz Exp $

MODNAME=		mhash
CATEGORIES+=		security
PKGREVISION=		# empty
COMMENT=		PHP4 extension for the mhash hash algorithms library

USE_BUILDLINK2=		yes

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.mhash}

.include "../../security/mhash/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
