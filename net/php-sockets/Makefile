# $NetBSD: Makefile,v 1.4 2005/04/11 21:46:57 tv Exp $

MODNAME=		sockets
CATEGORIES+=		net
PKGREVISION=		# empty
COMMENT=		PHP extension for sockets support


CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_DIR}

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
