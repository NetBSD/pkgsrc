# $NetBSD: Makefile,v 1.1.1.1 2003/12/14 13:55:47 jdolecek Exp $

MODNAME=		zip
CATEGORIES+=		archivers
PKGREVISION=		# empty
COMMENT=		PHP4 extension for ZIP archive handling

USE_BUILDLINK2=		YES

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_DIR}

.include "../../archivers/zziplib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
