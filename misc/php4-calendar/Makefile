# $NetBSD: Makefile,v 1.4 2002/11/05 07:33:16 martti Exp $

MODNAME=		calendar
CATEGORIES+=		misc
PKGREVISION=		# empty
COMMENT=		PHP4 extension for calendar conversion support

USE_BUILDLINK2= 	YES

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--enable-${MODNAME}

.include "../../mk/bsd.pkg.mk"
