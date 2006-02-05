# $NetBSD: Makefile,v 1.7 2006/02/05 23:10:29 joerg Exp $

MODNAME=		yp
PKGREVISION=		1
CATEGORIES+=		net
COMMENT=		PHP extension for YP domain support

# yp extension has been unbundled in PHP 5.1.1, it's only available
# in CVS and isn't available through have PECL; thus, mark this
# PHP4-only for now
PHP_VERSION_REQD=	4

CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_DIR}

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
