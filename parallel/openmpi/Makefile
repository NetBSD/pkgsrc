# $NetBSD: Makefile,v 1.49 2022/06/28 11:35:24 wiz Exp $

DISTNAME=	openmpi-1.10.7
PKGREVISION=	10
CATEGORIES=	parallel
MASTER_SITES=	http://www.open-mpi.org/software/ompi/v1.10/downloads/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	asau@inbox.ru
HOMEPAGE=	https://www.open-mpi.org/
COMMENT=	Open source MPI-3.1 implementation
LICENSE=	modified-bsd

CONFLICTS=	mpich-[0-9]*

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		perl:run
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-slurm
CONFIGURE_ARGS+=	--enable-contrib-no-build=vt # in separate package
CONFIGURE_ARGS+=	--with-libltdl=${BUILDLINK_PREFIX.libltdl}
CONFIGURE_ARGS+=	--with-hwloc=${BUILDLINK_PREFIX.hwloc}
CONFIGURE_ARGS+=	--with-wrapper-ldflags="-L${PREFIX}/lib ${LINKER_RPATH_FLAG}${PREFIX}/lib"
CONFIGURE_ARGS+=	OPAL_HAVE_LTDL_ADVISE=0
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool \
			${WRKSRC}/ompi/contrib/vt/vt/extlib/otf/libtool \
			${WRKSRC}/ompi/contrib/vt/vt/libtool \
			${WRKSRC}/ompi/mca/io/romio/romio/libtool
SHLIBTOOL_OVERRIDE=	${WRKSRC}/config/libtool.m4

# Prevent detection of OpenMP support in order to make PLIST consistent
BUILDLINK_TRANSFORM=	rm:-fopenmp

.include "options.mk"

TEST_TARGET=	check

PLIST_VARS+=	linux loadleveler oshmem pstattest shm
PLIST_VARS+=	ignoretkr noignoretkr

.if ${OPSYS} == "Linux"
PLIST.shm=		yes
PLIST.linux=		yes
PLIST.loadleveler=	yes
PLIST.oshmem=		yes
PLIST.ignoretkr=	yes
.elif ${OPSYS} == "AIX"
PLIST.loadleveler=	yes
.elif ${OPSYS} == "DragonFly" || ${OPSYS} == "FreeBSD" || \
    (${OPSYS} == "NetBSD" && exists(/var/shm))
PLIST.shm=		yes
.endif
.if ${OPSYS} != "Linux"
PLIST.pstattest=	yes
.  if ${OPSYS} != "Darwin"
PLIST.noignoretkr=	yes
.  endif
.endif

REPLACE_PERL=	ompi/tools/wrappers/mpijavac.pl.in

#LIBLTDL_CONVENIENCE_SUBDIR=	opal/libltdl
#.include "../../devel/libltdl/convenience.mk" # for "test" target to work
.include "../../devel/libltdl/buildlink3.mk"
.include "../../parallel/hwloc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
