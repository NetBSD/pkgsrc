# $NetBSD: Makefile,v 1.29 2003/01/16 03:05:01 uebayasi Exp $
#

DISTNAME=       siag-3.1.20
PKGREVISION=	1
CATEGORIES=     misc textproc math
MASTER_SITES=   ftp://ftp.edu.stockholm.se/pub/siag/

MAINTAINER=     packages@netbsd.org
HOMEPAGE=       http://siag.nu/
COMMENT=	Poor man's office suite with spreadsheet, word processor, etc

DEPENDS+=	gv>=3.5.8nb1:../../print/gv
DEPENDS+=	gnuplot>=3.7:../../graphics/gnuplot

CONFIGURE_ARGS=	--with-x --with-guile --includedir=${BUILDLINK_DIR}/include
GNU_CONFIGURE=  YES
USE_BUILDLINK2=	YES
USE_GMAKE=	YES
USE_X11=	YES

CFLAGS+=	-Dunix
_STRIPFLAG_INSTALL=

# XXX The source assumes Xaw3d.  Need work to use standard.
.include "../../mk/bsd.prefs.mk"

XAW_TYPE=	3d

.include "../../devel/ncurses/buildlink2.mk"
.include "../../lang/guile14/buildlink2.mk"
.include "../../graphics/xpm/buildlink2.mk"
.include "../../mk/xaw.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
