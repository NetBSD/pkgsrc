# $NetBSD: Makefile,v 1.5 2001/06/21 05:06:17 jlam Exp $

.include "../../games/freeciv-share/Makefile.common"

PKGNAME=		${DISTNAME:S/-/-share-/}
COMMENT=		Machine independent files for Freeciv

USE_BUILDLINK_ONLY=	# defined

CONFIGURE_ARGS+=	--disable-server
CONFIGURE_ARGS+=	--enable-client=no

.include "../../mk/bsd.pkg.mk"
