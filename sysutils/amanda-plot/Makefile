# $NetBSD: Makefile,v 1.4 2001/02/17 17:42:09 wiz Exp $
# FreeBSD Id: Makefile,v 1.9 1997/03/08 05:00:11 gpalmer Exp
#

DISTNAME=		amanda-2.4.2
PKGNAME=		amanda-plot-2.4.2
CATEGORIES=		sysutils
MASTER_SITES=		ftp://ftp.cs.umd.edu/pub/amanda/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.amanda.org/
COMMENT=		Visualizes the behavior of Amanda, a network backup system

DEPENDS+=		gnuplot-3.7:../../graphics/gnuplot
DEPENDS+=		amanda-server-2.4.2:../../sysutils/amanda-server

USE_X11=		yes

.include "../../mk/bsd.prefs.mk"
.include "../../sysutils/amanda-common/Makefile.common"

CONFIGURE_ARGS+=	--without-client --without-restore \
			--without-restore --without-amrecover
CONFIGURE_ENV+=		GNUPLOT="${LOCALBASE}/gnuplot"

.include "../../mk/bsd.pkg.mk"
