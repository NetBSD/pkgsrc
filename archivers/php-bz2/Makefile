# $NetBSD: Makefile,v 1.14 2025/02/08 03:03:11 taca Exp $

MODNAME=		bz2
PKGREVISION=		1
CATEGORIES=		archivers
COMMENT=		PHP extension for bzip2 compression

CONFLICTS=	php-bz2-[0-9]*

USE_PHP_EXT_PATCHES=	yes

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.bzip2}

.include "../../lang/php/ext.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
