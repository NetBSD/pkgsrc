# $NetBSD: Makefile,v 1.15 2008/05/15 20:22:02 drochner Exp $
#

PKGNAME=		${DISTNAME:C/-/-nox11-/}
SVR4_PKGNAME=		gplot

CONFLICTS+=		gnuplot-[0-9]*

CONFIGURE_ARGS+=	--without-x

INSTALL_ENV+=		INSTALL_XRESOURCE_DATA=no

.include "../../graphics/gnuplot/Makefile.common"

.include "../../graphics/plotutils-nox11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
