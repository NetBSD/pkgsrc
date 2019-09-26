# $NetBSD: Makefile,v 1.3 2019/09/26 00:54:56 wiz Exp $

R_PKGNAME=	tcltk2
R_PKGVER=	1.2-11
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Tcl/Tk additions
LICENSE=	gnu-lgpl-v3	# + file LICENSE

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	inst/tklibs/ttktheme_clearlooks/create_imgs.py

REPLACE_INTERPRETER+=	tcl
REPLACE.tcl.old=	.*tclsh[^[:space:]]*
REPLACE.tcl.new=	${TCLSH}
REPLACE_FILES.tcl=	inst/tklibs/ctext3.2/function_finder.tcl

REPLACE_INTERPRETER+=	wish
REPLACE.wish.old=	/usr/bin/wish
REPLACE.wish.new=	${PREFIX}/bin/wish
REPLACE_FILES.wish+=	inst/tklibs/notebook1.3/example.tcl
REPLACE_FILES.wish+=	inst/tklibs/tree1.7/tree.tcl
REPLACE_FILES.wish+=	inst/tklibs/tree1.7/example.tcl
REPLACE_FILES.wish+=	inst/tklibs/choosefont0.2/example.tcl

.include "../../math/R/Makefile.extension"
.include "../../lang/python/application.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
