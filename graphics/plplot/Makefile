# $NetBSD: Makefile,v 1.8 2001/02/16 15:22:31 wiz Exp $

DISTNAME=	plplot-5.0.2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=plplot/}

MAINTAINER=	jtb@netbsd.org
HOMEPAGE=	http://www.plplot.org/
COMMENT=	Scientific plotting package

DEPENDS+=	tcl>=8.3.0:../../lang/tcl
DEPENDS+= 	tk>=8.3.0:../../x11/tk
DEPENDS+=	m4-[0-9]*:../../devel/m4
BUILD_DEPENDS+=	${LOCALBASE}/bin/autoconf:../../devel/autoconf
BUILD_DEPENDS+=	perl:../../lang/perl5

GNU_CONFIGURE=	YES
USE_GMAKE=	YES
USE_FORTRAN=	YES
USE_X11=	YES

EVAL_PREFIX+=	TK_PREFIX=tk TCL_PREFIX=tcl

CONFIGURE_ENV+=	"BIN_DIR=${PREFIX}/bin"
CONFIGURE_ENV+=	"LIB_DIR=${PREFIX}/lib"
CONFIGURE_ENV+=	"INCLUDE_DIR=${PREFIX}/include/plplot"
CONFIGURE_ENV+=	"DATA_DIR=${PREFIX}/libdata/plplot"
CONFIGURE_ENV+=	"DOC_DIR=${PREFIX}/share/doc/plplot"
CONFIGURE_ENV+=	"DEMOS_DIR=${PREFIX}/share/examples/plplot"
CONFIGURE_ENV+=	"TCL_DIR=${PREFIX}/lib/tcl/plplot"
CONFIGURE_ENV+=	"TKINCDIR=${TK_PREFIX}/include"
CONFIGURE_ENV+=	"TKLIBDIR=${TK_PREFIX}/lib"
CONFIGURE_ENV+=	"TCLINCDIR=${TCL_PREFIX}/include"
CONFIGURE_ENV+=	"TCLLIBDIR=${TCL_PREFIX}/lib"
CONFIGURE_ENV+=	"USER_FLAGS_C=${CFLAGS}"
CONFIGURE_ENV+=	"USER_FLAGS_LC=${LDFLAGS}"
CONFIGURE_ENV+=	"USER_FLAGS_CXX=${CXXFLAGS}"
CONFIGURE_ENV+=	"USER_FLAGS_LCXX=${LDFLAGS}"
CONFIGURE_ENV+=	"USER_FLAGS_F=${FFLAGS}"
CONFIGURE_ENV+=	"USER_FLAGS_LF=${LDLAGS}"

CONFIGURE_ARGS+="--with-double"
CONFIGURE_ARGS+="--enable-xwin"
CONFIGURE_ARGS+="--enable-tcl"
CONFIGURE_ARGS+="--enable-tk"
CONFIGURE_ARGS+="--without-shlib"
CONFIGURE_ARGS+="--disable-python"
CONFIGURE_ARGS+="--disable-itcl"
CONFIGURE_ARGS+="--disable-dp"

post-patch:
	for f in ${WRKSRC}/src/plctrl.c ; do		\
	${SED} -e 's:@PREFIX@:'${PREFIX}':g'		\
	< $$f > $$f.tmp && ${MV} $$f.tmp $$f ; done

pre-configure:
	(cd ${WRKSRC}/cf && ${LOCALBASE}/bin/autoconf)
	${CP} ${WRKSRC}/cf/configure ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
