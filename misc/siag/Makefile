# $NetBSD: Makefile,v 1.14 1999/11/11 02:07:19 hubertf Exp $

DISTNAME=       siag-3.1.20
CATEGORIES=     misc textproc math
MASTER_SITES=   ftp://ftp.edu.stockholm.se/pub/siag/

MAINTAINER=     packages@netbsd.org
HOMEPAGE=       http://www.edu.stockholm.se/siag/

DEPENDS+=	gv-3.5.8:../../print/gv
DEPENDS+=	gnuplot-3.7:../../graphics/gnuplot
DEPENDS+=	guile-1.3.2:../../lang/guile
DEPENDS+=	xpm-3.4k:../../graphics/xpm

CONFIGURE_ARGS=	--with-x --with-guile --includedir=${PREFIX}/include
GNU_CONFIGURE=  yes
USE_GMAKE=	yes
USE_X11=	yes
USE_XAW=	yes

CFLAGS+=	-Dunix
LDFLAGS+=	-Wl,-R${X11BASE}/lib
STRIPFLAG=

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
DEPENDS+=	ncurses-4.2:../../devel/ncurses
.endif

XAW_TYPE?=	3d

.include "../../mk/bsd.pkg.mk"
