# $NetBSD: Makefile,v 1.2 2004/10/31 21:07:14 jdolecek Exp $

MODNAME=		calendar
CATEGORIES+=		misc
PKGREVISION=		# empty
COMMENT=		PHP extension for calendar conversion support

USE_BUILDLINK3= 	YES

.include "../../lang/php/ext.mk"

CONFIGURE_ARGS+=	--enable-${MODNAME}

.include "../../mk/bsd.pkg.mk"
