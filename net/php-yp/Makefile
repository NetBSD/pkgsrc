# $NetBSD: Makefile,v 1.9 2006/06/04 16:26:55 joerg Exp $

MODNAME=		yp
CATEGORIES+=		net
COMMENT=		PHP extension for YP domain support

CONFLICTS=	php-yp-[0-9]*

# yp extension has been unbundled in PHP 5.1.1, it's only available
# in CVS and isn't available through have PECL; thus, mark this
# PHP4-only for now
PHP_VERSIONS_ACCEPTED=	4

CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_DIR}

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
