# $NetBSD: Makefile,v 1.5 1999/03/05 01:52:32 hubertf Exp $

DISTNAME=       siag-3.1.7
CATEGORIES=     misc textproc math
MASTER_SITES=   ftp://ftp.edu.stockholm.se/pub/siag/

MAINTAINER=     packages@netbsd.org
HOMEPAGE=       http://www.edu.stockholm.se/siag/

DEPENDS+=	Xaw3d-1.5:../../x11/Xaw3d
DEPENDS+=	gv-3.5.8:../../print/gv
DEPENDS+=	gnuplot-3.7:../../graphics/gnuplot
DEPENDS+=	guile-1.3:../../lang/guile

GNU_CONFIGURE=  yes
USE_GMAKE=	yes

CFLAGS+=	-Dunix
LDFLAGS+=	-Wl,-R${X11BASE}/lib
STRIPFLAG=

post-install:
	${MV} ${PREFIX}/doc/siag ${PREFIX}/share/doc/siag
	${RMDIR} ${PREFIX}/doc

.include "../../mk/bsd.pkg.mk"
