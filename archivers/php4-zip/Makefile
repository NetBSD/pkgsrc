# $NetBSD: Makefile,v 1.4 2004/11/05 21:44:44 jdolecek Exp $

MODNAME=		zip
CATEGORIES+=		archivers
PKGREVISION=		# empty
COMMENT=		PHP4 extension for ZIP archive handling

USE_BUILDLINK3=		YES

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_DIR}

PHP_VERSION_REQD=	4
.include "../../lang/php/ext.mk"
.include "../../archivers/zziplib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
