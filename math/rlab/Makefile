# $NetBSD: Makefile,v 1.1.1.1 2001/01/31 07:30:25 jtb Exp $

DISTNAME=		rlab-2.1.05
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=rlab/}

MAINTAINER=		jtb@netbsd.org
HOMEPAGE=		http://rlab.sourceforge.net/

DEPENDS+=		boehm-gc-[0-9]*:../../devel/boehm-gc
DEPENDS+=		readline-[0-9]*:../../devel/readline
BUILD_DEPENDS+=		autoconf:../../devel/autoconf

GNU_CONFIGURE=		YES
USE_FORTRAN=		YES

EVAL_PREFIX+=		GC_PREFIX=boehm-gc
CONFIGURE_ARGS+=	"--with-GC=${GC_PREFIX}"

.include "../../mk/bsd.prefs.mk"

RLAB_PLOT_PKG?=		gnuplot
.if (${RLAB_PLOT_PKG} == "plplot")
DEPENDS+=		plplot>=5.0.1:../../graphics/plplot
EVAL_PREFIX+=		PLPLOT_PREFIX=plplot TCL_PREFIX=tcl TK_PREFIX=tk
CONFIGURE_ARGS+=	"--with-tk=${TK_PREFIX}"
CONFIGURE_ARGS+=	"--with-plplot=${PLPLOT_PREFIX}"
CONFIGURE_ARGS+=	"--with-tcl=${TCL_PREFIX}"
PLIST_SRC+=		${PKGDIR}/PLIST.plplot
.elif (${RLAB_PLOT_PKG} == "plotmtv")
DEPENDS+=		plotmtv-[0-9]*:../../graphics/plotmtv
CONFIGURE_ARGS+=	"--with-plotmtv=yes"
PLIST_SRC+=		${PKGDIR}/PLIST.plotmtv
.else
DEPENDS+=		gnuplot-[0-9]*:../../graphics/gnuplot
CONFIGURE_ARGS+=	"--with-gnuplot=yes"
PLIST_SRC+=		${PKGDIR}/PLIST.gnuplot
.endif

pre-configure:
		(cd ${WRKSRC} && autoconf)

.include "../../mk/bsd.pkg.mk"
