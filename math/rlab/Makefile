# $NetBSD: Makefile,v 1.18 2004/04/25 21:39:05 snj Exp $

DISTNAME=		rlab-2.1.05
PKGREVISION=		1
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=rlab/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://rlab.sourceforge.net/
COMMENT=		Matrix oriented, interactive programming environment

BROKEN=			relies on API from older version of superlu

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes
USE_FORTRAN=		yes
CONFIGURE_ARGS+=	--enable-SUPERLU

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

post-extract:
	${RM} -r ${WRKSRC}/gc

post-install:
.if (${RLAB_PLOT_PKG} == "pgraf")
	${INSTALL_DATA} ${PGRAF_PREFIX}/share/examples/pgraf/pgraf.r \
	${PREFIX}/share/rlab/rlib
	${INSTALL_DATA} ${PGRAF_PREFIX}/share/examples/pgraf/pgdemo.r \
	${PREFIX}/share/rlab/examples
.endif

.include "../../devel/boehm-gc/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../math/superlu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
