# $NetBSD: Makefile,v 1.17 2000/08/23 23:14:30 tron Exp $

DISTNAME=       siag-3.1.20
CATEGORIES=     misc textproc math
MASTER_SITES=   ftp://ftp.edu.stockholm.se/pub/siag/

MAINTAINER=     packages@netbsd.org
HOMEPAGE=       http://www.edu.stockholm.se/siag/

DEPENDS+=	gv-3.5.8:../../print/gv
DEPENDS+=	gnuplot-3.7:../../graphics/gnuplot
DEPENDS+=	guile-1.3.*:../../lang/guile

CONFIGURE_ARGS=	--with-x --with-guile --includedir=${PREFIX}/include
GNU_CONFIGURE=  YES
USE_GMAKE=	YES
USE_X11=	YES
USE_XAW=	YES
USE_XPM=	YES

CFLAGS+=	-Dunix
LDFLAGS+=	-Wl,-R${X11BASE}/lib
STRIPFLAG=

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
DEPENDS+=	ncurses>=4.2:../../devel/ncurses
.endif

XAW_TYPE?=	3d

.include "../../mk/bsd.pkg.mk"
