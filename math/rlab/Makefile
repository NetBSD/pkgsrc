# $NetBSD: Makefile,v 1.10 2001/05/03 22:16:51 jtb Exp $

DISTNAME=		rlab-2.1.05
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=rlab/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://rlab.sourceforge.net/
COMMENT=		Matrix oriented, interactive programming environment

DEPENDS+=		boehm-gc>=5.3:../../devel/boehm-gc
DEPENDS+=		readline>=4.0:../../devel/readline

BUILD_DEPENDS+=		autoconf>=2.13:../../devel/autoconf

GNU_CONFIGURE=		yes
USE_FORTRAN=		yes

GC_PREFIX_DEFAULT=	${LOCALBASE}
EVAL_PREFIX+=		GC_PREFIX=boehm-gc
CONFIGURE_ARGS+=	--with-GC=${GC_PREFIX}

PLIST_SRC=		${PKGDIR}/PLIST

.include "../../mk/bsd.prefs.mk"

RLAB_PLOT_PKG?=		gnuplot
.if (${RLAB_PLOT_PKG} == "plplot")
DEPENDS+=		plplot>=5.0.1:../../graphics/plplot
PLPLOT_PREFIX_DEFAULT=	${LOCALBASE}
EVAL_PREFIX+=		PLPLOT_PREFIX=plplot
CONFIGURE_ARGS+=	--with-plplot=${PLPLOT_PREFIX}
PLIST_SRC+=		${PKGDIR}/PLIST.plplot
.elif (${RLAB_PLOT_PKG} == "plotmtv")
DEPENDS+=		plotmtv-[0-9]*:../../graphics/plotmtv
CONFIGURE_ARGS+=	--with-plotmtv=yes
PLIST_SRC+=		${PKGDIR}/PLIST.plotmtv
.elif (${RLAB_PLOT_PKG} == "pgraf")
DEPENDS+=		pgraf-[0-9]*:../../graphics/pgraf
PGRAF_PREFIX_DEFAULT=	${LOCALBASE}
EVAL_PREFIX+=		PGRAF_PREFIX=pgraf
CONFIGURE_ARGS+=	--with-pgraf=yes
PLIST_SRC+=		${PKGDIR}/PLIST.pgraf
.else
DEPENDS+=		gnuplot>=3.5:../../graphics/gnuplot
CONFIGURE_ARGS+=	--with-gnuplot=yes
PLIST_SRC+=		${PKGDIR}/PLIST.gnuplot
.endif

RLAB_USE_SUPERLU?=	YES
.if (${RLAB_USE_SUPERLU} == YES)
DEPENDS+=		superlu-[0-9]*:../../math/superlu
CONFIGURE_ARGS+=	--enable-SUPERLU
.endif

.if defined(RLAB_PAGER)
CONFIGURE_ENV+=		PAGER=${RLAB_PAGER}
.endif

pre-configure:
	(cd ${WRKSRC} && ${LOCALBASE}/bin/autoconf)

post-install:
.if (${RLAB_PLOT_PKG} == "pgraf")
	${INSTALL_DATA} ${PGRAF_PREFIX}/share/examples/pgraf/pgraf.r \
	${PREFIX}/share/rlab/rlib
	${INSTALL_DATA} ${PGRAF_PREFIX}/share/examples/pgraf/pgdemo.r \
	${PREFIX}/share/rlab/examples
.endif

.include "../../mk/bsd.pkg.mk"
