# $NetBSD: Makefile,v 1.2 2004/10/31 21:07:13 jdolecek Exp $

MODNAME=		bz2
CATEGORIES+=		archivers
PKGREVISION=		# empty
COMMENT=		PHP extension for bzip2 compression

USE_BUILDLINK3=		YES

.include "../../lang/php/ext.mk"

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.bzip2}

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
