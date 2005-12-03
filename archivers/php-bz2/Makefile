# $NetBSD: Makefile,v 1.8 2005/12/03 18:53:57 jdolecek Exp $

MODNAME=		bz2
CATEGORIES=		archivers
COMMENT=		PHP extension for bzip2 compression

USE_PHP_EXT_PATCHES=	yes

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.bzip2}

.include "../../lang/php/ext.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
