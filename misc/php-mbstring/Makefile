# $NetBSD: Makefile,v 1.6 2006/02/05 23:10:13 joerg Exp $

MODNAME=		mbstring
CATEGORIES+=		misc
PKGREVISION=		2
COMMENT=		PHP extension for multibyte characters support (currently, Japanese only)

USE_PHP_EXT_PATCHES=	yes

CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_DIR}

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
