# $NetBSD: Makefile,v 1.22 2006/05/26 13:19:38 joerg Exp $
#

PKGNAME=		amanda-plot-${VERS}
PKGREVISION=		3
SVR4_PKGNAME=		amapl

COMMENT=		Visualizes the behavior of Amanda, a network backup system

DEPENDS+=		gnuplot>=3.7:../../graphics/gnuplot
DEPENDS+=		amanda-server-2.4.4p4{,nb[0-9]*}:../../sysutils/amanda-server


.include "../../mk/bsd.prefs.mk"
.include "../../sysutils/amanda-common/Makefile.common"

CONFIGURE_ARGS+=	--without-client
CONFIGURE_ARGS+=	--without-restore
CONFIGURE_ARGS+=	--without-amrecover
CONFIGURE_ENV+=		GNUPLOT="${LOCALBASE}/bin/gnuplot"

.include "../../mk/bsd.pkg.mk"
