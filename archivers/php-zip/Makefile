# $NetBSD: Makefile,v 1.5 2006/02/05 23:08:04 joerg Exp $

MODNAME=		zip
PECL_VERSION=		1.0
PKGREVISION=		2
CATEGORIES+=		archivers
COMMENT=		PHP extension for ZIP archive handling


CONFIGURE_ARGS+=	--with-zip=shared,${BUILDLINK_DIR}

.include "../../lang/php/ext.mk"
.include "../../archivers/zziplib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
