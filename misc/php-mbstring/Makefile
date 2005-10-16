# $NetBSD: Makefile,v 1.5 2005/10/16 12:17:47 jdolecek Exp $

MODNAME=		mbstring
CATEGORIES+=		misc
PKGREVISION=		1
COMMENT=		PHP extension for multibyte characters support (currently, Japanese only)

USE_PHP_EXT_PATCHES=	yes

CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_DIR}

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
