# $NetBSD: Makefile,v 1.22 2001/08/23 04:26:54 jlam Exp $

DISTNAME=       siag-3.1.20
CATEGORIES=     misc textproc math
MASTER_SITES=   ftp://ftp.edu.stockholm.se/pub/siag/

MAINTAINER=     packages@netbsd.org
HOMEPAGE=       http://siag.nu/
COMMENT=	Poor man's office suite with spreadsheet, word processor, etc

DEPENDS+=	gv-3.5.8:../../print/gv
DEPENDS+=	gnuplot>=3.7:../../graphics/gnuplot
DEPENDS+=	guile>=1.3:../../lang/guile

CONFIGURE_ARGS=	--with-x --with-guile --includedir=${PREFIX}/include
GNU_CONFIGURE=  YES
USE_CURSES=	YES
REPLACE_NCURSES=	${WRKSRC}/tsiag/window.c ${WRKSRC}/configure
USE_GMAKE=	YES
USE_X11=	YES
USE_XAW=	YES
USE_XPM=	YES

CFLAGS+=	-Dunix
LDFLAGS+=	-Wl,-R${X11BASE}/lib
STRIPFLAG=

XAW_TYPE?=	3d

.include "../../mk/bsd.pkg.mk"
