# $NetBSD: Makefile,v 1.51 2007/06/12 02:55:16 dmcmahill Exp $
#
# Note: I have tried to update this package to 3.6.0, but there were
# some undefined identifiers "DndDrop" and "DndRawData" in the
# xsiag/window.c file.

DISTNAME=	siag-3.5.7
PKGREVISION=	8
CATEGORIES=	misc textproc math
MASTER_SITES=	ftp://siag.nu/pub/siag/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://siag.nu/
COMMENT=	Poor man's office suite with spreadsheet, word processor, etc

DEPENDS+=	gv>=3.5.8nb1:../../print/gv
DEPENDS+=	gnuplot>=3.7:../../graphics/gnuplot

CONFLICTS+=	antiword-[0-9]*

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
