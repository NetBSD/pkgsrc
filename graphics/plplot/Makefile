# $NetBSD: Makefile,v 1.1.1.1 2000/12/02 05:40:26 jtb Exp $

DISTNAME=	plplot4p99j
PKGNAME=	plplot-4.99
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.uniovi.es/pub6/graphics/plotting/ \
		ftp://dino.ph.utexas.edu/plplot/distrib/alpha/ \
		ftp://ftp.u-aizu.ac.jp/pub/misc/tools/plot/plplot/distrib/alpha/ \
		ftp://ftp.che.utexas.edu/pub/graphics/

MAINTAINER=	jtb@netbsd.org
HOMEPAGE=	http://www.plplot.org/

GNU_CONFIGURE=	YES
USE_GMAKE=	YES
USE_FORTRAN=	YES

EVAL_PREFIX+=	TK_PREFIX=tk TCL_PREFIX=tcl PYTHON_PREFIX=python

post-patch:
	@for f in ${WRKSRC}/src/plctrl.c ; do  \
	${SED} -e 's:%%PREFIX%%:'${PREFIX}':g' \
	< $$f > $$f.tmp && ${MV} $$f.tmp $$f ; done

PLPLOT_USE_X11= YES
PLPLOT_USE_TCL= YES
PLPLOT_USE_TK = YES

CONFIGURE_ENV+=	"LIB_DIR=${PREFIX}/lib/plplot"
CONFIGURE_ENV+=	"BIN_DIR=${PREFIX}/bin"
CONFIGURE_ENV+=	"DOC_DIR=${PREFIX}/share/doc/plplot"
CONFIGURE_ENV+=	"INCLUDE_DIR=${PREFIX}/include/plplot"
CONFIGURE_ENV+=	"DEMOS_DIR=${PREFIX}/share/examples/plplot"

# Python support requires shared libraries. Disabled for now.
#CONFIGURE_ENV+="PYTHONLIBDIR=${PYTHON_PREFIX}/lib/python1.5"
#CONFIGURE_ENV+="PYTHON_INC_DIR=${PYTHON_PREFIX}/include/python1.5"
#CONFIGURE_ENV+="PYTHON_MOD_DIR=${PYTHON_PREFIX}/lib/python1.5/site-packages"
#CONFIGURE_ENV+="PYTHON_DIR=${PREFIX}/libdata/plplot/python"

CONFIGURE_ARGS+="--with-double"
CONFIGURE_ARGS+="--without-shlib"
CONFIGURE_ARGS+="--disable-python"
CONFIGURE_ARGS+="--disable-itcl"
CONFIGURE_ARGS+="--disable-dp"

.include "../../mk/bsd.prefs.mk"

PLIST_SRC=	${PKGDIR}/PLIST.no-x11

.if defined(PLPLOT_USE_TK) && ${PLPLOT_USE_TK} == "YES"
DEPENDS+= 	tk-8.3.[0-9]:../../x11/tk
USE_X11=	YES
PLPLOT_USE_X11= YES
PLPLOT_USE_TCL= YES
PLIST_SRC=	${PKGDIR}/PLIST.xwin-tcl-tk
CONFIGURE_ARGS+="--enable-tk"
CONFIGURE_ENV+=	"TKINCDIR=${TK_PREFIX}/include"
CONFIGURE_ENV+=	"TKLIBDIR=${TK_PREFIX}/lib"
.else
CONFIGURE_ARGS+="--disable-tk"
.endif

.if defined(PLPLOT_USE_X11) && ${PLPLOT_USE_X11} == "NO"
CONFIGURE_ARGS+="--disable-xwin"
.else
USE_X11=	YES
CONFIGURE_ARGS+="--enable-xwin"
.if ${PLPLOT_USE_TK} == "NO" && ${PLPLOT_USE_TCL} == "NO"
PLIST_SRC=	${PKGDIR}/PLIST.xwin
.endif
.endif

.if defined(PLPLOT_USE_TCL) && ${PLPLOT_USE_TCL} == "YES"
DEPENDS+=	tcl-8.3.[0-9]:../../lang/tcl
.if ${PLPLOT_USE_X11} == "NO"
PLIST_SRC=	${PKGDIR}/PLIST.tcl
.endif
CONFIGURE_ARGS+="--enable-tcl"
CONFIGURE_ENV+=	"TCLINCDIR=${TCL_PREFIX}/include"
CONFIGURE_ENV+=	"TCLLIBDIR=${TCL_PREFIX}/lib"
CONFIGURE_ENV+=	"TCL_DIR=${PREFIX}/libdata/plplot/tcl"
.else
CONFIGURE_ARGS+="--disable-tcl"
.endif

.include "../../mk/bsd.pkg.mk"
