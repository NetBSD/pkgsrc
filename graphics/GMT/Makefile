# $NetBSD: Makefile,v 1.5 2001/01/27 10:36:53 jtb Exp $

DISTNAME=	GMT3.3.6
PKGNAME=	GMT-3.3.6
CATEGORIES=	graphics
MASTER_SITES=	ftp://gmt.soest.hawaii.edu/pub/gmt/ \
		ftp://falcon.grdl.noaa.gov/pub/gmt/ \
		ftp://ftp.iag.usp.br/pub/gmt/ \
		ftp://ftp.geologi.uio.no/pub/gmt/ \
		ftp://life.csu.edu.au/pub/gmt/ \
		ftp://ftp.eos.hokudai.ac.jp/pub/gmt/
DISTFILES=	GMT3.3.6_progs.tar.bz2 GMT3.3.6_doc.tar.bz2 GMT_share.tar.bz2 \
		GMT3.3.6_suppl.tar.bz2 GMT3.3.6_scripts.tar.bz2		      \
		GMT3.3.6_web.tar.bz2

MAINTAINER=	jtb@netbsd.org
HOMEPAGE=	http://imina.soest.hawaii.edu/gmt/

DEPENDS+=	netcdf>=3.0:../../devel/netcdf
BUILD_DEPENDS+=	autoreconf:../../devel/autoconf

EXTRACT_SUFFIX= .tar.bz2
WRKSRC=		${WRKDIR}/${DISTNAME}
USE_X11=	YES
USE_XAW=	YES
DIST_SUBDIR=	GMT
GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
EVAL_PREFIX+=	NETCDF=netcdf

CONFIGURE_ARGS+="--includedir=${PREFIX}/include/gmt"
CONFIGURE_ARGS+="--datadir=${PREFIX}/share/gmt"
CONFIGURE_ARGS+="--enable-eps"
CONFIGURE_ARGS+="--enable-www=${PREFIX}/share/doc/html"
CONFIGURE_ARGS+="--enable-mansect=1"

ALL_TARGET=	all suppl
INSTALL_TARGET= install-all

post-extract:
	${MV} -f ${WRKSRC}/www/gmt/doc/ps/ ${WRKSRC}

pre-configure:
	(cd ${WRKSRC} && autoreconf)
	for e in ${WRKSRC}/examples/*.bat			\
	${WRKSRC}/examples/*/*.bat; do				\
	${RM} -f $$e;						\
	done
	for h in ${WRKSRC}/examples/do_view.bash		\
	${WRKSRC}/examples/do_view.csh ; do			\
	${SED} -e 's:ghostview:gv:g' < $$h > $$h.tmp &&		\
	${MV} -f $$h.tmp $$h;					\
	done

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/gmt
	for f in GMT_Docs.ps GMT_Tutorial.ps ; do			\
	${INSTALL_DATA} ${WRKSRC}/ps/$$f ${PREFIX}/share/doc/gmt;	\
	done
	(cd ${PREFIX}/share/doc/html/gmt/doc && ${LN} -sf		\
	../../../gmt ps)
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/gmt/tutorial
	for f in bermuda.grd quakes.cpt ship.xyz us.grd data quakes.ngdc \
	topo.cpt ; do							 \
	${INSTALL_DATA} ${WRKSRC}/tutorial/$$f				 \
	${PREFIX}/share/examples/gmt/tutorial;				 \
	done;
	${INSTALL_DATA} ${WRKSRC}/../share/* ${PREFIX}/share/gmt
	for i in ${WRKSRC}/examples/*.bash ${WRKSRC}/examples/*.csh	\
	${WRKSRC}/examples/README.SCRIPTS ; do				\
	${INSTALL_DATA} $$i ${PREFIX}/share/examples/gmt;		\
	done
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/gmt
	for f in README.SCRIPTS do_examples.bash do_examples.csh	\
	do_view.bash do_view.csh; do					\
	${INSTALL_DATA} ${WRKSRC}/examples/$$f				\
	${PREFIX}/share/examples/gmt;					\
	done
	for i in 01 02 03 04 05 06 07 08 09 10 				\
	11 12 13 14 15 16 17 18 19 20 ; do				\
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/gmt/ex$$i;		\
	for j in ${WRKSRC}/examples/ex$$i/* ; do			\
	${INSTALL_DATA} $$j ${PREFIX}/share/examples/gmt/ex$$i;		\
	done;								\
	done

.include "../../mk/bsd.pkg.mk"
