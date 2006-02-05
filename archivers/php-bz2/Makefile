# $NetBSD: Makefile,v 1.9 2006/02/05 23:08:04 joerg Exp $

MODNAME=		bz2
PKGREVISION=		1
CATEGORIES=		archivers
COMMENT=		PHP extension for bzip2 compression

USE_PHP_EXT_PATCHES=	yes

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.bzip2}

.include "../../lang/php/ext.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
