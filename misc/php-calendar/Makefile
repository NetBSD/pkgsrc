# $NetBSD: Makefile,v 1.3 2004/11/05 17:11:40 jdolecek Exp $

MODNAME=		calendar
CATEGORIES+=		misc
PKGREVISION=		# empty
COMMENT=		PHP extension for calendar conversion support

USE_BUILDLINK3= 	YES

CONFIGURE_ARGS+=	--enable-${MODNAME}

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
