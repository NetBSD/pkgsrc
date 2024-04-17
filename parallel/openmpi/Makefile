# $NetBSD: Makefile,v 1.53 2024/04/17 14:50:01 adam Exp $

DISTNAME=	openmpi-4.1.6
CATEGORIES=	parallel
MASTER_SITES=	https://download.open-mpi.org/release/open-mpi/v${PKGVERSION_NOREV:R}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	thor@NetBSD.org
HOMEPAGE=	https://www.open-mpi.org/
COMMENT=	Open source MPI-3.1 implementation
LICENSE=	modified-bsd

CONFLICTS=	mpich-[0-9]*

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		perl:run bash:run
GNU_CONFIGURE=		yes
CONFIG_SHELL=		bash
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--enable-contrib-no-build=vt # in separate package
CONFIGURE_ARGS+=	--with-libltdl=${BUILDLINK_PREFIX.libltdl}
# See below about external hwloc.
#CONFIGURE_ARGS+=	--with-hwloc=${BUILDLINK_PREFIX.hwloc}
# OSHM Needs additional dependencies and also is surpassed with proper MPI
# functionality. Rare use cases.
CONFIGURE_ARGS+=	--disable-oshmem
CONFIGURE_ARGS+=	OPAL_HAVE_LTDL_ADVISE=0
LIBTOOL_OVERRIDE=	libtool \
			ompi/contrib/vt/vt/extlib/otf/libtool \
			ompi/contrib/vt/vt/libtool \
			ompi/mca/io/romio/romio/libtool
SHLIBTOOL_OVERRIDE=	config/libtool.m4

.include "options.mk"

TEST_TARGET=	check

# CPU with AVX support.
PLIST_VARS+=	avx
# \todo Explain.  Apparently built if !Linux.
PLIST_VARS+=	pstattest
# \todo Explain.
PLIST_VARS+=	ignoretkr

.if ${MACHINE_ARCH} == "x86_64"
PLIST.avx=		yes
.endif

.if ${OPSYS} != "Linux"
PLIST.pstattest=	yes
.endif

.if ${OPSYS} == "Darwin" || ${OPSYS} == "Linux" || ${OPSYS} == "NetBSD"
PLIST.ignoretkr=	yes
.endif

REPLACE_PERL=	ompi/tools/wrappers/mpijavac.pl.in
REPLACE_PERL+=	ompi/mca/common/monitoring/*.pl

EGDIR=			${PREFIX}/share/examples/openmpi
CONF_SAMPLES+=		openmpi-default-hostfile openmpi-mca-params.conf
CONF_SAMPLES+=		pmix-mca-params.conf
.for i in ${CONF_SAMPLES}
CONF_FILES+=		${EGDIR}/${i} ${PKG_SYSCONFDIR}/${i}
.endfor

INSTALLATION_DIRS+=	${EGDIR}

post-install:
.for i in ${CONF_SAMPLES}
	${MV} ${DESTDIR}${PKG_SYSCONFDIR}/${i} ${DESTDIR}${EGDIR}/${i}
.endfor

.include "../../devel/libltdl/buildlink3.mk"
# Too old, use internal hwloc 2 instead. As hwloc 2 API/ABI is incompatible,
# upgrade has to be considered carefully.
#.include "../../parallel/hwloc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
