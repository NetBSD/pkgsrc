# $NetBSD: Makefile,v 1.73 2024/05/16 06:15:00 wiz Exp $

DISTNAME=	GMT4.1.4
PKGNAME=	GMT-4.1.4
PKGREVISION=	32
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.scc.u-tokai.ac.jp/pub/gmt/4/
MASTER_SITES+=	ftp://ftp.iris.washington.edu/pub/gmt/4/
DISTFILES=	GMT4.1.4_man.tar.bz2 GMT4.1.4_pdf.tar.bz2	\
		GMT4.1.4_scripts.tar.bz2 GMT4.1.4_share.tar.bz2 \
		GMT4.1.4_src.tar.bz2 GMT4.1.4_suppl.tar.bz2	\
		GMT4.1.4_tut.tar.bz2 GMT4.1.4_web.tar.bz2	\
		GMT4.1_coast.tar.bz2 GMT4.1_high.tar.bz2	\
		GMT4.1_full.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gmt.soest.hawaii.edu/
COMMENT=	Generic Mapping Tools
LICENSE=	gnu-gpl-v2

MAKE_JOBS_SAFE=		no

EXTRACT_SUFX=	.tar.bz2
DIST_SUBDIR=	${DISTNAME}

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pax

CONFIGURE_ARGS+=	--includedir=${PREFIX}/include/gmt
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/gmt
CONFIGURE_ARGS+=	--enable-eps
CONFIGURE_ARGS+=	--enable-netcdf=${BUILDLINK_PREFIX.netcdf}
CONFIGURE_ARGS+=	--enable-www=${PREFIX}/share/doc
CONFIGURE_ARGS+=	--enable-mansect=1
CONFIGURE_ARGS+=	--disable-mex

BUILD_TARGET=	all suppl
INSTALL_TARGET=	install-all
LIBS+=		${X11_LDFLAGS} # XXX: LDFLAGS doesn't work

post-extract:
	${RM} -f ${WRKSRC}/examples/*.bat ${WRKSRC}/examples/*/*.bat

INSTALLATION_DIRS=	share/doc/gmt share/examples/gmt/tutorial share/gmt

pre-install:
	rm -f ${WRKSRC}/share/.gmtdefaults_SI.orig
	rm -f ${WRKSRC}/share/.gmtdefaults_US.orig
	rm -f ${WRKSRC}/share/gmt.conf.orig

post-install:
	cd ${WRKSRC}/tutorial && ${INSTALL_DATA} bermuda.nc quakes.cpt	\
		ship.xyz us.nc data quakes.ngdc topo.cpt		\
		${DESTDIR}${PREFIX}/share/examples/gmt/tutorial
	cd ${WRKSRC}/share && pax -rw . ${DESTDIR}${PREFIX}/share/gmt
	cd ${WRKDIR}/share && pax -rw . ${DESTDIR}${PREFIX}/share/gmt
	cd ${WRKSRC}/examples && pax -rw . ${DESTDIR}${PREFIX}/share/examples/gmt

.include "../../devel/netcdf/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
