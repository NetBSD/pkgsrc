# $NetBSD: Makefile,v 1.12 2008/06/12 02:14:13 joerg Exp $

MODNAME=		bz2
CATEGORIES=		archivers
COMMENT=		PHP extension for bzip2 compression

CONFLICTS=	php-bz2-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PHP_EXT_PATCHES=	yes

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.bzip2}

.include "../../lang/php/ext.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
