# $NetBSD: Makefile,v 1.3 2005/10/04 16:50:50 tv Exp $

MODNAME=		zip
PECL_VERSION=		1.0
PKGREVISION=		1
CATEGORIES+=		archivers
PKGREVISION=		# empty
COMMENT=		PHP extension for ZIP archive handling


CONFIGURE_ARGS+=	--with-zip=shared,${BUILDLINK_DIR}

.include "../../lang/php/ext.mk"
.include "../../archivers/zziplib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
