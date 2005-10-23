# $NetBSD: Makefile,v 1.4 2005/10/23 18:12:24 rillig Exp $

MODNAME=		zip
PECL_VERSION=		1.0
PKGREVISION=		1
CATEGORIES+=		archivers
COMMENT=		PHP extension for ZIP archive handling


CONFIGURE_ARGS+=	--with-zip=shared,${BUILDLINK_DIR}

.include "../../lang/php/ext.mk"
.include "../../archivers/zziplib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
