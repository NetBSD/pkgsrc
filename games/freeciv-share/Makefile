# $NetBSD: Makefile,v 1.7 2002/09/23 10:02:50 jlam Exp $

PKGNAME=		${DISTNAME:S/-/-share-/}
COMMENT=		Machine independent files for Freeciv

.include "../freeciv-share/Makefile.common"

CONFIGURE_ARGS+=	--disable-server
CONFIGURE_ARGS+=	--enable-client=no

.include "../../mk/bsd.pkg.mk"
