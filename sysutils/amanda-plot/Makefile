# $NetBSD: Makefile,v 1.2 1999/09/06 19:30:20 bad Exp $
# FreeBSD Id: Makefile,v 1.9 1997/03/08 05:00:11 gpalmer Exp
#

DISTNAME=		amanda-2.4.1p1
PKGNAME=		amanda-plot-2.4.1p1
CATEGORIES=		sysutils
MASTER_SITES=		ftp://ftp.cs.umd.edu/pub/amanda/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.amanda.org/

DEPENDS+=		gnuplot-3.7:../../graphics/gnuplot
DEPENDS+=		amanda-server-2.4.1p1:../../sysutils/amanda-server

USE_X11=		yes

.include "../../mk/bsd.prefs.mk"
.include "../../sysutils/amanda-common/Makefile.common"

CONFIGURE_ARGS+=	--without-client --without-restore
CONFIGURE_ENV+=		GNUPLOT="${LOCALBASE}/gnuplot"

.include "../../mk/bsd.pkg.mk"
