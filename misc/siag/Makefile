# $NetBSD: Makefile,v 1.25.2.1 2002/06/23 18:54:19 jlam Exp $
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
DEPENDS+=	guile>=1.3:../../lang/guile

CONFIGURE_ARGS=	--with-x --with-guile --includedir=${BUILDLINK_DIR}/include
GNU_CONFIGURE=  YES
USE_BUILDLINK_ONLY=	YES
USE_GMAKE=	YES

CFLAGS+=	-Dunix
_STRIPFLAG_INSTALL=

XAW_TYPE?=	3d

.include "../../devel/ncurses/buildlink.mk"
.include "../../graphics/xpm/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/xaw.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
