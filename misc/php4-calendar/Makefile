# $NetBSD: Makefile,v 1.5 2004/04/25 00:20:38 xtraeme Exp $

MODNAME=		calendar
CATEGORIES+=		misc
PKGREVISION=		# empty
COMMENT=		PHP4 extension for calendar conversion support

USE_BUILDLINK3= 	YES

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--enable-${MODNAME}

.include "../../mk/bsd.pkg.mk"
