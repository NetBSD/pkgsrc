# $NetBSD: Makefile,v 1.1.1.1 2013/03/16 12:43:26 asau Exp $

DISTNAME=	mpqc-2.3.1
CATEGORIES=	biology
MASTER_SITES=	$(MASTER_SITE_SOURCEFORGE:=mpqc/)
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	asau@inbox.ru
HOMEPAGE=	http://www.mpqc.org/
COMMENT=	The Massively Parallel Quantum Chemistry Program

USE_LANGUAGES=	c c++ fortran77
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-libdirs="$(COMPILER_RPATH_FLAG)$(PREFIX)/lib"	# fixme
#CONFIGURE_ARGS=	-without-f77	# this doesn't work out of the box
CONFIGURE_ENV=	ac_cv_prog_WISH=$(REPLACE.wish.new)
USE_TOOLS+=	perl:run
USE_LIBTOOL=	yes

USE_TOOLS+=	gmake
BUILD_TARGET=	default

# This is strange, yet...
INSTALL_MAKE_FLAGS=	installroot=$(DESTDIR)

REPLACE_PERL=	src/bin/mpqc/ccarun.in src/bin/mpqc/mpqcrun.in
REPLACE_WISH=	src/bin/molrender/tkmolrender.in

# optional:
# MPI, niama-config, libr12, libderiv
.include "../../devel/libexecinfo/buildlink3.mk" # optional
.include "../../mk/dlopen.buildlink3.mk" # optional?
.include "../../math/libint/buildlink3.mk" # optional

.include "../../x11/tk/interpreter.mk"

.include "../../math/blas/buildlink3.mk"
.include "../../math/lapack/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
