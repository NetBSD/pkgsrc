# $NetBSD: Makefile,v 1.3 2002/02/28 06:18:13 jlam Exp $

MODNAME=		calendar
CATEGORIES+=		misc
PKGREVISION=		# empty
COMMENT=		PHP4 extension for calendar conversion support

USE_BUILDLINK_ONLY=	YES

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--enable-${MODNAME}

.include "../../mk/bsd.pkg.mk"
