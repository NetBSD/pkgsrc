# $NetBSD: Makefile,v 1.3 2002/02/28 06:18:33 jlam Exp $

MODNAME=		yp
CATEGORIES+=		net
PKGREVISION=		# empty
COMMENT=		PHP4 extension for YP domain support

USE_BUILDLINK_ONLY=	YES

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_DIR}

.include "../../mk/bsd.pkg.mk"
