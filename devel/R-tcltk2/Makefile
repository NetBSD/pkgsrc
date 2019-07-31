# $NetBSD: Makefile,v 1.1 2019/07/31 01:24:09 brook Exp $

CATEGORIES=	devel R

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/tcltk2/
COMMENT=	Tcl/Tk additions
LICENSE=	gnu-lgpl-v3	# + file LICENSE

R_PKGNAME=	tcltk2
R_PKGVER=	1.2-11

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
