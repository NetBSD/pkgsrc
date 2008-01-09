# $NetBSD: Makefile,v 1.52 2008/01/09 19:16:15 reed Exp $
#

DISTNAME=       siag-3.6.1
CATEGORIES=     misc editors math textproc
MASTER_SITES=   ftp://siag.nu/pub/siag/		\
		http://siag.nu/pub/siag/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=       http://siag.nu/
COMMENT=	Poor man's office suite with spreadsheet, word processor, etc

#DEPENDS+=	gv>=3.5.8nb1:../../print/gv
#DEPENDS+=	gnuplot>=3.7:../../graphics/gnuplot

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-x
CONFIGURE_ARGS+=--with-guile
CONFIGURE_ARGS+=--with-docdir=${PREFIX:Q}/share/doc/siag
USE_TOOLS+=	gmake

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=	XAW_TYPE

.if ${XAW_TYPE} == "xpm"
CONFIGURE_ARGS+=--with-xawm=XawXpm
.elif ${XAW_TYPE} == "3d"
CONFIGURE_ARGS+=--with-xawm=Xaw3d
.elif ${XAW_TYPE} == "neXtaw"
CONFIGURE_ARGS+=--with-xawm=neXtaw
.else
CONFIGURE_ARGS+=--with-xawm=Xaw
.endif

.include "../../devel/ncurses/buildlink3.mk"
.include "../../lang/guile16/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/mowitz/buildlink3.mk"
.include "../../mk/xaw.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
