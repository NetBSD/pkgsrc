# $NetBSD: Makefile,v 1.3 2004/10/31 21:28:51 jdolecek Exp $

MODNAME=		zip
CATEGORIES+=		archivers
PKGREVISION=		# empty
COMMENT=		PHP4 extension for ZIP archive handling

USE_BUILDLINK3=		YES

PHP_VERSION_REQD=	4
.include "../../lang/php/ext.mk"

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_DIR}

.include "../../archivers/zziplib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
