# $NetBSD: Makefile,v 1.6 2005/12/05 20:50:48 rillig Exp $

MODNAME=		yp
CATEGORIES+=		net
COMMENT=		PHP extension for YP domain support

# yp extension has been unbundled in PHP 5.1.1, it's only available
# in CVS and isn't available through have PECL; thus, mark this
# PHP4-only for now
PHP_VERSION_REQD=	4

CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_DIR}

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
