# $NetBSD: Makefile,v 1.30 2003/01/17 02:09:36 uebayasi Exp $
#

DISTNAME=       siag-3.5.4
CATEGORIES=     misc textproc math
MASTER_SITES=   ftp://siag.nu/pub/siag/

MAINTAINER=     packages@netbsd.org
HOMEPAGE=       http://siag.nu/
COMMENT=	Poor man's office suite with spreadsheet, word processor, etc

DEPENDS+=	gv>=3.5.8nb1:../../print/gv
DEPENDS+=	gnuplot>=3.7:../../graphics/gnuplot

CONFIGURE_ARGS+=--with-x
CONFIGURE_ARGS+=--with-guile
CONFIGURE_ARGS+=--with-docdir=${PREFIX}/share/doc/siag
GNU_CONFIGURE=  YES
USE_BUILDLINK2=	YES
USE_GMAKE=	YES
USE_X11=	YES

#CFLAGS+=	-Dunix
#_STRIPFLAG_INSTALL=

.include "../../mk/bsd.prefs.mk"

.if ${XAW_TYPE} == "xpm"
CONFIGURE_ARGS+=--with-xawm=XawXpm
.elif ${XAW_TYPE} == "3d"
CONFIGURE_ARGS+=--with-xawm=Xaw3d
.elif ${XAW_TYPE} == "neXtaw"
CONFIGURE_ARGS+=--with-xawm=neXtaw
.else
CONFIGURE_ARGS+=--with-xawm=Xaw
.endif

.include "../../devel/ncurses/buildlink2.mk"
.include "../../lang/guile14/buildlink2.mk"
.include "../../graphics/xpm/buildlink2.mk"
.include "../../mk/xaw.buildlink2.mk"
.include "../../x11/mowitz/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
