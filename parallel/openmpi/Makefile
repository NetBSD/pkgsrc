# $NetBSD: Makefile,v 1.11 2011/11/01 06:11:57 sbd Exp $

DISTNAME=	openmpi-1.5.4
PKGREVISION=	1
CATEGORIES=	parallel
MASTER_SITES=	http://www.open-mpi.org/software/ompi/v1.5/downloads/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	asau@inbox.ru
HOMEPAGE=	http://www.open-mpi.org/
COMMENT=	Open source MPI-2 implementation

CONFLICTS+=	mpich-[0-9]*	# installs bin/mpicc & other wrappers
CONFLICTS+=	mpich2-[0-9]*	# installs bin/mpicc & other wrappers

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++ fortran77
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool \
			${WRKSRC}/ompi/contrib/vt/vt/extlib/otf/libtool \
			${WRKSRC}/ompi/contrib/vt/vt/libtool \
			${WRKSRC}/ompi/mca/io/romio/romio/libtool
SHLIBTOOL_OVERRIDE=	${WRKSRC}/config/libtool.m4 \
			${WRKSRC}/opal/libltdl/m4/libtool.m4

CONFIGURE_ARGS+=	--disable-mpi-f90
CONFIGURE_ARGS+=	--with-libltdl=external # use our libltdl
CONFIGURE_ARGS+=	--with-wrapper-ldflags="-L${PREFIX}/lib ${LINKER_RPATH_FLAG}${PREFIX}/lib"
CONFIGURE_ENV+=		ompi_cv_f77_have_INTEGERp8=no	# no "INTEGER*8"??
CONFIGURE_ARGS+=	OPAL_HAVE_LTDL_ADVISE=0

USE_TOOLS+=		perl:run

.include "options.mk"

TEST_TARGET=	check

## Just in case you'll need it...
# USE_TOOLS+=	aclocal autoconf automake bash perl
# REPLACE_BASH=	autogen.sh

# pre-configure:	replace-interpreter
# 	cd $(WRKSRC) && $(BASH) autogen.sh

.include "../../devel/libltdl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
