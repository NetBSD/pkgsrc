# $NetBSD: Makefile,v 1.41 2019/08/11 13:23:02 wiz Exp $
#

PKGNAME=		amanda-plot-${AMANDA_VERSION}
PKGREVISION=		1

COMMENT=		Visualizes the behavior of Amanda, a network backup system

DEPENDS+=		gnuplot>=3.7:../../graphics/gnuplot
DEPENDS+=		amanda-server-${AMANDA_VERSION}{,nb[0-9]*}:../../sysutils/amanda-server

MANPAGES+=		amplot.8

.include "../../sysutils/amanda-common/Makefile.common"

CONFIGURE_ARGS+=	--without-client
CONFIGURE_ARGS+=	--without-restore
CONFIGURE_ARGS+=	--without-amrecover
CONFIGURE_ENV+=		GNUPLOT="${LOCALBASE}/bin/gnuplot"

BUILD_DIRS=		amplot

.include "../../mk/bsd.pkg.mk"
