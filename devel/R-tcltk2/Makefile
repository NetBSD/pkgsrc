# $NetBSD: Makefile,v 1.2 2019/08/08 19:53:40 brook Exp $

R_PKGNAME=	tcltk2
R_PKGVER=	1.2-11
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

.include "../../math/R/Makefile.extension"
.include "../../lang/python/application.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
