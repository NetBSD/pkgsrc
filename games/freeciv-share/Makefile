# $NetBSD: Makefile,v 1.6 2001/08/15 19:50:31 jlam Exp $

PKGNAME=		${DISTNAME:S/-/-share-/}
COMMENT=		Machine independent files for Freeciv

USE_BUILDLINK_ONLY=	# defined

.include "../freeciv-share/Makefile.common"

CONFIGURE_ARGS+=	--disable-server
CONFIGURE_ARGS+=	--enable-client=no

.include "../../mk/bsd.pkg.mk"
