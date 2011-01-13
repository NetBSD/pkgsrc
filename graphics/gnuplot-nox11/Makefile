# $NetBSD: Makefile,v 1.24 2011/01/13 13:38:05 wiz Exp $
#

PKGNAME=		${DISTNAME:C/-/-nox11-/}
PKGREVISION=		5

CONFLICTS+=		gnuplot-[0-9]*

CONFIGURE_ARGS+=	--without-x

INSTALL_ENV+=		INSTALL_XRESOURCE_DATA=no

.include "../../graphics/gnuplot/Makefile.common"

.include "../../graphics/plotutils-nox11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
