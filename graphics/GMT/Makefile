# $NetBSD: Makefile,v 1.1.1.1 2000/11/26 22:48:12 jtb Exp $

DISTNAME=	GMT3.3.6
PKGNAME=	GMT-3.3.6
CATEGORIES=	graphics
MASTER_SITES=	ftp://gmt.soest.hawaii.edu/pub/gmt/ \
		ftp://falcon.grdl.noaa.gov/pub/gmt/ \
		ftp://ftp.iag.usp.br/pub/gmt/ \
		ftp://ftp.geologi.uio.no/pub/gmt/ \
		ftp://life.csu.edu.au/pub/gmt/ \
		ftp://ftp.eos.hokudai.ac.jp/pub/gmt/
DISTFILES=	GMT3.3.6_progs.tar.bz2 GMT3.3.6_doc.tar.bz2 GMT_share.tar.bz2

MAINTAINER=	jtb@netbsd.org
HOMEPAGE=	http://imina.soest.hawaii.edu/gmt/

DEPENDS+=	netcdf>=3.0:../../devel/netcdf
BUILD_DEPENDS+=	${LOCALBASE}/bin/autoreconf:../../devel/autoconf

EXTRACT_SUFFIX= .tar.bz2
WRKSRC=		${WRKDIR}/${DISTNAME}

DIST_SUBDIR=	GMT
GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
EVAL_PREFIX+=	NETCDF=netcdf

CONFIGURE_ARGS+="--includedir=${PREFIX}/include/gmt"
CONFIGURE_ARGS+="--datadir=${PREFIX}/share/gmt"
CONFIGURE_ARGS+="--enable-eps"
INSTALL_TARGET= install install-man install-data

pre-configure:
	@(cd ${WRKSRC} && ${LOCALBASE}/bin/autoreconf 2>/dev/null)

do-build:
	@(cd ${WRKSRC}/src && ${MAKE})

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/gmt
	@for f in GMT_Docs.ps GMT_Tutorial.ps ; do \
	${INSTALL_DATA} ${WRKSRC}/www/gmt/doc/ps/$$f ${PREFIX}/share/doc/gmt; \
	done
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/gmt/tutorial
	@for f in bermuda.grd quakes.cpt ship.xyz us.grd data quakes.ngdc \
	topo.cpt ; do \
	${INSTALL_DATA} ${WRKSRC}/tutorial/$$f ${PREFIX}/share/examples/gmt; \
	done;
	${INSTALL_DATA} ${WRKSRC}/../share/* ${PREFIX}/share/gmt

.include "../../mk/bsd.pkg.mk"
