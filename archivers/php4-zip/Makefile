# $NetBSD: Makefile,v 1.2 2004/04/24 23:13:57 xtraeme Exp $

MODNAME=		zip
CATEGORIES+=		archivers
PKGREVISION=		# empty
COMMENT=		PHP4 extension for ZIP archive handling

USE_BUILDLINK3=		YES

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_DIR}

.include "../../archivers/zziplib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
