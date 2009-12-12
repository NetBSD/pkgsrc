# $NetBSD: Makefile,v 1.1.1.1 2009/12/12 23:30:01 asau Exp $

DISTNAME=	openmpi-1.4
CATEGORIES=	parallel
MASTER_SITES=	http://www.open-mpi.org/software/ompi/v1.4/downloads/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	asau@inbox.ru
HOMEPAGE=	http://www.open-mpi.org/
COMMENT=	Open source MPI-2 implementation

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++ fortran
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
SHLIBTOOL_OVERRIDE=	${WRKSRC}/config/libtool.m4

CONFIGURE_ARGS+=	--disable-mpi-f90
CONFIGURE_ARGS+=	--with-wrapper-ldflags="-L${PREFIX}/lib ${LINKER_RPATH_FLAG}${PREFIX}/lib"
CONFIGURE_ENV+=		ompi_cv_f77_have_INTEGERp8=no	# no "INTEGER*8"??
BUILD_MAKE_FLAGS=	LIBLTDL=$(BUILDLINK_PREFIX.libltdl)/lib/libltdl.la # configure doesn't allow overriding it
CONFIGURE_ARGS+=	OPAL_HAVE_LTDL_ADVISE=0

.include "options.mk"

TEST_TARGET=	check

.include "../../devel/libltdl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
