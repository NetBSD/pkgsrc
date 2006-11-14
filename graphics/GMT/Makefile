# $NetBSD: Makefile,v 1.29 2006/11/14 13:16:00 wennmach Exp $

DISTNAME=	GMT4.1.4
PKGNAME=	GMT-4.1.4
#PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.soest.hawaii.edu/gmt/4/		\
		ftp://falcon.grdl.noaa.gov/pub/gmt/4/		\
		ftp://ftp.iris.washington.edu/pub/gmt/4/	\
		ftp://ftp.iag.usp.br/pub/gmt/4/			\
		ftp://ftp.geologi.uio.no/pub/gmt/4/		\
		ftp://gd.tuwien.ac.at/pub/gmt/4/		\
		ftp://life.csu.edu.au/pub/gmt/4/		\
		ftp://ftp.scc.u-tokai.ac.jp/pub/gmt/4/
DISTFILES=	GMT4.1.4_man.tar.bz2 GMT4.1.4_pdf.tar.bz2	\
		GMT4.1.4_scripts.tar.bz2 GMT4.1.4_share.tar.bz2 \
		GMT4.1.4_src.tar.bz2 GMT4.1.4_suppl.tar.bz2	\
		GMT4.1.4_tut.tar.bz2 GMT4.1.4_web.tar.bz2	\
		GMT4.1_coast.tar.bz2 GMT4.1_high.tar.bz2	\
		GMT4.1_full.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gmt.soest.hawaii.edu/
COMMENT=	Generic Mapping Tools

EXTRACT_SUFX=	.tar.bz2
DIST_SUBDIR=	${DISTNAME}

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

CONFIGURE_ARGS+=--includedir=${PREFIX}/include/gmt
CONFIGURE_ARGS+=--datadir=${PREFIX}/share/gmt
CONFIGURE_ARGS+=--enable-eps
CONFIGURE_ARGS+=--enable-netcdf=${BUILDLINK_PREFIX.netcdf:Q}
CONFIGURE_ARGS+=--enable-www=${PREFIX}/share/doc/html
CONFIGURE_ARGS+=--enable-mansect=1
CONFIGURE_ARGS+=--disable-mex

BUILD_TARGET=	all suppl
INSTALL_TARGET= install-all

.include "../../mk/x11.buildlink3.mk"

post-extract:
	${MV} -f ${WRKSRC}/www/gmt/doc/pdf ${WRKSRC}
	${RM} -f ${WRKSRC}/examples/*.bat ${WRKSRC}/examples/*/*.bat

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/gmt
	cd ${WRKSRC}/pdf && ${INSTALL_DATA} GMT_Docs.pdf		\
		 GMT_Tutorial.pdf ${PREFIX}/share/doc/gmt
	(cd ${PREFIX}/share/doc/html/gmt/doc && ${LN} -sf		\
	../../../gmt pdf)
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/gmt/tutorial
	cd ${WRKSRC}/tutorial && ${INSTALL_DATA} bermuda.nc quakes.cpt	\
		ship.xyz us.nc data quakes.ngdc topo.cpt		\
		${PREFIX}/share/examples/gmt/tutorial;
	${INSTALL_DATA_DIR} ${PREFIX}/share/gmt
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${WRKSRC}/share
	cd ${WRKSRC}/share && ${PAX} -rw . ${PREFIX}/share/gmt
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/gmt
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${WRKSRC}/examples/
	cd ${WRKSRC}/examples && ${PAX} -rw . ${PREFIX}/share/examples/gmt
	${RM} ${PREFIX}/share/gmt/.gmtdefaults_SI.orig
	${RM} ${PREFIX}/share/gmt/.gmtdefaults_US.orig
	${RM} ${PREFIX}/share/gmt/gmt.conf.orig
	cd ${WRKDIR}/share && ${PAX} -rw . ${PREFIX}/share/gmt

.include "../../devel/netcdf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
