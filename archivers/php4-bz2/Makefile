# $NetBSD: Makefile,v 1.4 2002/10/05 03:57:34 wiz Exp $

MODNAME=		bz2
CATEGORIES+=		archivers
PKGREVISION=		# empty
COMMENT=		PHP4 extension for bzip2 compression

USE_BUILDLINK2=		YES

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.bzip2}

.include "../../archivers/bzip2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
