# $NetBSD: Makefile,v 1.8 2006/06/04 16:26:54 joerg Exp $

MODNAME=		mbstring
CATEGORIES+=		misc
COMMENT=		PHP extension for multibyte characters support (currently, Japanese only)

CONFLICTS=	php-mbstring-[0-9]*

USE_PHP_EXT_PATCHES=	yes

CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_DIR}

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
