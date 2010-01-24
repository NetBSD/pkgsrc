# $NetBSD: Makefile,v 1.21 2010/01/24 13:26:10 wiz Exp $
#

PKGNAME=		${DISTNAME:C/-/-nox11-/}
PKGREVISION=		2

CONFLICTS+=		gnuplot-[0-9]*

CONFIGURE_ARGS+=	--without-x

INSTALL_ENV+=		INSTALL_XRESOURCE_DATA=no

.include "../../graphics/gnuplot/Makefile.common"

.include "../../graphics/plotutils-nox11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
