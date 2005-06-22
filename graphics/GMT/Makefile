# $NetBSD: Makefile,v 1.25 2005/06/22 08:34:54 jlam Exp $

DISTNAME=	GMT3.4
PKGNAME=	GMT-3.4
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	ftp://gmt.soest.hawaii.edu/pub/gmt/ \
		ftp://falcon.grdl.noaa.gov/pub/gmt/ \
		ftp://ftp.iag.usp.br/pub/gmt/ \
		ftp://ftp.geologi.uio.no/pub/gmt/ \
		ftp://life.csu.edu.au/pub/gmt/ \
		ftp://ftp.eos.hokudai.ac.jp/pub/gmt/
DISTFILES=	GMT3.4_progs.tar.bz2 GMT3.4_suppl.tar.bz2 GMT_share.tar.bz2 \
		GMT3.4_ps.tar.bz2 GMT3.4_man.tar.bz2 GMT3.4_tut.tar.bz2 \
		GMT3.4_scripts.tar.bz2 GMT3.4_web.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://gmt.soest.hawaii.edu/
COMMENT=	Generic Mapping Tools

EXTRACT_SUFX=	.tar.bz2
DIST_SUBDIR=	${DISTNAME}

WRKSRC=		${WRKDIR}/${DISTNAME}
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

CONFIGURE_ARGS+=--includedir=${PREFIX}/include/gmt
CONFIGURE_ARGS+=--datadir=${PREFIX}/share/gmt
CONFIGURE_ARGS+=--enable-eps
CONFIGURE_ARGS+=--enable-www=${PREFIX}/share/doc/html
CONFIGURE_ARGS+=--enable-mansect=1
MAKE_ENV+=	NETCDFHOME=${BUILDLINK_PREFIX.netcdf:Q}
MAKE_ENV+=	LIBTOOL=${LIBTOOL:Q}

BUILD_TARGET=	all suppl
INSTALL_TARGET= install-all

post-extract:
	${MV} -f ${WRKSRC}/www/gmt/doc/ps/ ${WRKSRC}
	${RM} -f ${WRKSRC}/examples/*.bat ${WRKSRC}/examples/*/*.bat
	for f in ${WRKSRC}/examples/do_view.bash			\
		${WRKSRC}/examples/do_view.csh; do			\
		${SED} -e 's:ghostview:gv:g' $$f > $$f.tmp &&		\
		${MV} -f $$f.tmp $$f;					\
	done

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/gmt
	cd ${WRKSRC}/ps && ${INSTALL_DATA} GMT_Docs.ps GMT_Tutorial.ps 	\
		${PREFIX}/share/doc/gmt
	(cd ${PREFIX}/share/doc/html/gmt/doc && ${LN} -sf		\
	../../../gmt ps)
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/gmt/tutorial
	cd ${WRKSRC}/tutorial && ${INSTALL_DATA} bermuda.grd quakes.cpt \
		ship.xyz us.grd data quakes.ngdc 			\
		${PREFIX}/share/examples/gmt/tutorial;
	${INSTALL_DATA} ${WRKSRC}/../share/* ${PREFIX}/share/gmt
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/gmt
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${WRKSRC}/examples/
	cd ${WRKSRC}/examples && ${PAX} -rw . ${PREFIX}/share/examples/gmt

.include "../../devel/netcdf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
