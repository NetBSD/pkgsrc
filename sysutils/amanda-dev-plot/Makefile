# $NetBSD: Makefile,v 1.1.1.1 2002/05/02 13:28:15 bouyer Exp $
# FreeBSD Id: Makefile,v 1.9 1997/03/08 05:00:11 gpalmer Exp
#

PKGNAME=		amanda-plot-${VERS}
SVR4_PKGNAME=		amapl

COMMENT=		Visualizes the behavior of Amanda, a network backup system

DEPENDS+=		gnuplot>=3.7:../../graphics/gnuplot
DEPENDS+=		amanda-server-${VERS}:../../sysutils/amanda-dev-server

USE_X11=		yes

.include "../../mk/bsd.prefs.mk"
.include "../../sysutils/amanda-dev-common/Makefile.common"

CONFIGURE_ARGS+=	--without-client --without-restore \
			--without-restore --without-amrecover
CONFIGURE_ENV+=		GNUPLOT="${LOCALBASE}/bin/gnuplot"

.include "../../mk/bsd.pkg.mk"
