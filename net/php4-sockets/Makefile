# $NetBSD: Makefile,v 1.3 2002/02/28 06:18:29 jlam Exp $

MODNAME=		sockets
CATEGORIES+=		net
PKGREVISION=		# empty
COMMENT=		PHP4 extension for sockets support

USE_BUILDLINK_ONLY=	YES

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_DIR}

.include "../../mk/bsd.pkg.mk"
