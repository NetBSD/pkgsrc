# $NetBSD: Makefile,v 1.7 2006/06/04 16:26:52 joerg Exp $

MODNAME=		zip
PECL_VERSION=		1.0
CATEGORIES+=		archivers
COMMENT=		PHP extension for ZIP archive handling

CONFLICTS=	php-zip-[0-9]*

CONFIGURE_ARGS+=	--with-zip=shared,${BUILDLINK_DIR}

.include "../../lang/php/ext.mk"
.include "../../archivers/zziplib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
