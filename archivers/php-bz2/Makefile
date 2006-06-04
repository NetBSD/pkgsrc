# $NetBSD: Makefile,v 1.11 2006/06/04 16:26:52 joerg Exp $

MODNAME=		bz2
CATEGORIES=		archivers
COMMENT=		PHP extension for bzip2 compression

CONFLICTS=	php-bz2-[0-9]*

USE_PHP_EXT_PATCHES=	yes

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.bzip2}

.include "../../lang/php/ext.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
