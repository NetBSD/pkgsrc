# $NetBSD: Makefile,v 1.4 1999/02/09 16:08:58 bad Exp $

DISTNAME=       siag-3.1.2
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

pre-configure:
	cd ${WRKSRC} ; \
	[ -f topdir.mk.BAK ] || ${MV} topdir.mk topdir.mk.BAK ; \
	${SED} \
		-e 's|^\(SIAG_HOME\)=.*$$|\1="${PREFIX}/lib/siag"|g' \
		-e 's|^\(SIAG_DOCS\)=.*$$|\1=${PREFIX}/share/siag|g' \
		-e 's|^\(CURSES\)=.*$$|\1=-lcurses -ltermcap|g' \
		<topdir.mk.BAK >topdir.mk

.include "../../mk/bsd.pkg.mk"
