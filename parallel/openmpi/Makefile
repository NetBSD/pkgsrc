# $NetBSD: Makefile,v 1.34 2016/02/28 19:47:41 joerg Exp $

DISTNAME=	openmpi-1.10.1
PKGREVISION=	1
CATEGORIES=	parallel
MASTER_SITES=	http://www.open-mpi.org/software/ompi/v1.10/downloads/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	asau@inbox.ru
HOMEPAGE=	http://www.open-mpi.org/
COMMENT=	Open source MPI-2 implementation

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++ fortran77
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool \
			${WRKSRC}/ompi/contrib/vt/vt/extlib/otf/libtool \
			${WRKSRC}/ompi/contrib/vt/vt/libtool \
			${WRKSRC}/ompi/mca/io/romio/romio/libtool
SHLIBTOOL_OVERRIDE=	${WRKSRC}/config/libtool.m4

CONFIGURE_ARGS+=	--without-slurm
CONFIGURE_ARGS+=	--enable-contrib-no-build=vt # in separate package
CONFIGURE_ARGS+=	--with-libltdl=$(BUILDLINK_PREFIX.libltdl:Q) # use our libltdl
CONFIGURE_ARGS+=	--with-hwloc=$(BUILDLINK_PREFIX.hwloc:Q) #external
CONFIGURE_ARGS+=	--with-wrapper-ldflags="-L${PREFIX}/lib ${LINKER_RPATH_FLAG}${PREFIX}/lib"
CONFIGURE_ENV+=		ompi_cv_f77_have_INTEGERp8=no	# no "INTEGER*8"??
CONFIGURE_ARGS+=	OPAL_HAVE_LTDL_ADVISE=0

# Prevent detection of OpenMP support in order to make PLIST consistent:
BUILDLINK_TRANSFORM=	rm:-fopenmp

USE_TOOLS+=		perl:run

.include "options.mk"

TEST_TARGET=	check

PLIST_VARS+=	f08 linux loadleveler oshmem pstattest shm
PLIST_VARS+=	ignoretkr noignoretkr

.if ${OPSYS} == "Linux"
PLIST.shm=		yes
PLIST.linux=		yes
PLIST.loadleveler=	yes
PLIST.oshmem=		yes
PLIST.ignoretkr=	yes
PLIST.f08=		yes
.elif ${OPSYS} == "AIX"
PLIST.loadleveler=	yes
.elif ${OPSYS} == "DragonFly" || ${OPSYS} == "FreeBSD" || \
    (${OPSYS} == "NetBSD" && exists(/var/shm))
PLIST.shm=		yes
.endif
.if ${OPSYS} != "Linux"
PLIST.pstattest=	yes
PLIST.noignoretkr=	yes
.endif

## Just in case you'll need it...
# USE_TOOLS+=	aclocal autoconf automake bash perl
# REPLACE_BASH=	autogen.sh

REPLACE_PERL=	 ompi/tools/wrappers/mpijavac.pl.in

# pre-configure:	replace-interpreter
# 	cd $(WRKSRC) && $(BASH) autogen.sh

#LIBLTDL_CONVENIENCE_SUBDIR=	opal/libltdl
#.include "../../devel/libltdl/convenience.mk" # for "test" target to work
.include "../../devel/libltdl/buildlink3.mk"
.include "../../parallel/hwloc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
