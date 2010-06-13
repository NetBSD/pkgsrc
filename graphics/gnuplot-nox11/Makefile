# $NetBSD: Makefile,v 1.22 2010/06/13 22:44:33 wiz Exp $
#

PKGNAME=		${DISTNAME:C/-/-nox11-/}
PKGREVISION=		3

CONFLICTS+=		gnuplot-[0-9]*

CONFIGURE_ARGS+=	--without-x

INSTALL_ENV+=		INSTALL_XRESOURCE_DATA=no

.include "../../graphics/gnuplot/Makefile.common"

.include "../../graphics/plotutils-nox11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
