# $NetBSD: Makefile,v 1.2 2004/10/31 21:07:14 jdolecek Exp $

MODNAME=		yp
CATEGORIES+=		net
PKGREVISION=		# empty
COMMENT=		PHP extension for YP domain support

USE_BUILDLINK3=		YES

.include "../../lang/php/ext.mk"

CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_DIR}

.include "../../mk/bsd.pkg.mk"
