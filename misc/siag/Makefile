# $NetBSD: Makefile,v 1.8 1999/07/13 17:52:41 mjl Exp $

DISTNAME=       siag-3.1.20
CATEGORIES=     misc textproc math
MASTER_SITES=   ftp://ftp.edu.stockholm.se/pub/siag/

MAINTAINER=     packages@netbsd.org
HOMEPAGE=       http://www.edu.stockholm.se/siag/

DEPENDS+=	Xaw3d-1.5:../../x11/Xaw3d
DEPENDS+=	gv-3.5.8:../../print/gv
DEPENDS+=	gnuplot-3.7:../../graphics/gnuplot
DEPENDS+=	guile-1.3:../../lang/guile
DEPENDS+=	ncurses-4.2:../../devel/ncurses

CONFIGURE_ARGS=	--with-x --with-guile --includedir=${PREFIX}/include
GNU_CONFIGURE=  yes
USE_GMAKE=	yes
USE_X11=	yes

CFLAGS+=	-Dunix
LDFLAGS+=	-Wl,-R${X11BASE}/lib
STRIPFLAG=

post-install:
	${MV} ${PREFIX}/doc/siag ${PREFIX}/share/doc/siag
	${RMDIR} ${PREFIX}/doc

.include "../../mk/bsd.pkg.mk"
