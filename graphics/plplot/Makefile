# $NetBSD: Makefile,v 1.16 2001/04/30 04:16:10 jlam Exp $

DISTNAME=	plplot-5.0.3
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=plplot/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.plplot.org/
COMMENT=	Scientific plotting package

DEPENDS+=	tcl>=8.3.0:../../lang/tcl
DEPENDS+= 	tk>=8.3.0:../../x11/tk
BUILD_DEPENDS+=	m4>=1.4:../../devel/m4
BUILD_DEPENDS+=	autoconf>=2.13:../../devel/autoconf
BUILD_DEPENDS+=	perl>=${PERL5_REQD}:../../lang/perl5

GNU_CONFIGURE=	#defined
USE_GMAKE=	#defined
USE_FORTRAN=	#defined
USE_X11=	#defined

EVAL_PREFIX+=	TK_PREFIX=tk TCL_PREFIX=tcl

CONFIGURE_ENV+=	BIN_DIR="${PREFIX}/bin"
CONFIGURE_ENV+=	LIB_DIR="${PREFIX}/lib"
CONFIGURE_ENV+=	INCLUDE_DIR="${PREFIX}/include/plplot"
CONFIGURE_ENV+=	DATA_DIR="${PREFIX}/libdata/plplot"
CONFIGURE_ENV+=	DOC_DIR="${PREFIX}/share/doc/plplot"
CONFIGURE_ENV+=	DEMOS_DIR="${PREFIX}/share/examples/plplot"
CONFIGURE_ENV+=	TCL_DIR="${PREFIX}/lib/tcl/plplot"
CONFIGURE_ENV+=	TKINCDIR="${TK_PREFIX}/include"
CONFIGURE_ENV+=	TKLIBDIR="${TK_PREFIX}/lib"
CONFIGURE_ENV+=	TCLINCDIR="${TCL_PREFIX}/include"
CONFIGURE_ENV+=	TCLLIBDIR="${TCL_PREFIX}/lib"
CONFIGURE_ENV+=	USER_FLAGS_C="${CFLAGS}"
CONFIGURE_ENV+=	USER_FLAGS_LC="${LDFLAGS}"
CONFIGURE_ENV+=	USER_FLAGS_CXX="${CXXFLAGS}"
CONFIGURE_ENV+=	USER_FLAGS_LCXX="${LDFLAGS}"
CONFIGURE_ENV+=	USER_FLAGS_F="${FFLAGS}"
CONFIGURE_ENV+=	USER_FLAGS_LF="${LDLAGS}"

CONFIGURE_ARGS+=--with-double
CONFIGURE_ARGS+=--enable-xwin
CONFIGURE_ARGS+=--enable-tcl
CONFIGURE_ARGS+=--enable-tk
CONFIGURE_ARGS+=--without-shlib
CONFIGURE_ARGS+=--disable-python
CONFIGURE_ARGS+=--disable-itcl
CONFIGURE_ARGS+=--disable-dp

post-patch:
	${MV} -f ${WRKSRC}/src/plctrl.c ${WRKSRC}/src/plctrl.c.dist
	${SED} -e 's:@PREFIX@:'${PREFIX}':g' ${WRKSRC}/src/plctrl.c.dist \
		> ${WRKSRC}/src/plctrl.c

pre-configure:
	(cd ${WRKSRC}/cf && ${LOCALBASE}/bin/autoconf)
	${CP} ${WRKSRC}/cf/configure ${WRKSRC}

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/plplotdoc-0.4.1.dvi 		\
	${PREFIX}/share/doc/plplot
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/plplot
	${INSTALL_DATA} ${WRKSRC}/doc/plplotdoc-html-0.4.1/*.html	\
	${PREFIX}/share/doc/html/plplot

.include "../../mk/bsd.pkg.mk"
