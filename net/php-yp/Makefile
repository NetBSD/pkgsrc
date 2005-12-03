# $NetBSD: Makefile,v 1.5 2005/12/03 19:50:31 jdolecek Exp $

MODNAME=		yp
CATEGORIES+=		net
PKGREVISION=		# empty
COMMENT=		PHP extension for YP domain support

# yp extension has been unbundled in PHP 5.1.1, it's only available
# in CVS and isn't available through have PECL; thus, mark this
# PHP4-only for now
PHP_VERSION_REQD=	4

CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_DIR}

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
