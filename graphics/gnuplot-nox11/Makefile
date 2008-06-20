# $NetBSD: Makefile,v 1.16 2008/06/20 01:09:22 joerg Exp $
#

PKGNAME=		${DISTNAME:C/-/-nox11-/}
SVR4_PKGNAME=		gplot

CONFLICTS+=		gnuplot-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir

CONFIGURE_ARGS+=	--without-x

INSTALL_ENV+=		INSTALL_XRESOURCE_DATA=no

.include "../../graphics/gnuplot/Makefile.common"

.include "../../graphics/plotutils-nox11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
