# $NetBSD: Makefile,v 1.106 2012/12/16 01:52:23 obache Exp $

DISTNAME=	octave-${OCTAVE_VER}
PKGREVISION=	3
CATEGORIES=	math
MASTER_SITES=	$(MASTER_SITE_GNU:=octave/) \
		ftp://ftp.octave.org/pub/octave/ \
		ftp://ftp.octave.org/pub/octave/bleeding-edge/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.octave.org/
COMMENT=	High-level language, intended for numerical computations

BUILD_DEPENDS+=	gperf>=2.7:../../devel/gperf
BUILD_DEPENDS+=	teTeX-[0-9]*:../../print/teTeX
DEPENDS+=	gnuplot>=3.7:../../graphics/gnuplot

OCTAVE_VER=	3.6.3

.if (${MACHINE_ARCH} == "arm32")
BROKEN=		Internal compiler error occurs on arm32 (even with gcc-2.95.3)
.endif

USE_GNU_READLINE=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		autoconf gsed gmake:run makeinfo perl pkg-config bison
GNU_CONFIGURE=		yes

GCC_REQD+=		3.0
USE_LANGUAGES=		c c++ fortran77

# needed for loading of shared objects such as those in the
# octave-forge package or user written ones compiled with mkoctfile
CONFIGURE_ARGS+=	--enable-dl
CONFIGURE_ARGS+=	--enable-static
CONFIGURE_ARGS+=	--enable-shared

.include "options.mk"

INFO_FILES=	yes
OCTAVE_DOC=	faq/Octave-FAQ.ps  liboctave/liboctave.ps \
		refcard/refcard-a4.ps refcard/refcard-legal.ps \
		refcard/refcard-letter.ps

INSTALLATION_DIRS+=	share/octave/${OCTAVE_VER}/doc
UNWRAP_FILES+=		src/mkoctfile octave-bug src/oct-conf.h

TEST_TARGET=	check

#pre-configure:
#	cd ${WRKSRC} && autoconf

SUBST_CLASSES+=			fix-info
SUBST_STAGE.fix-info=		post-patch
SUBST_MESSAGE.fix-info=		Fixing info files.
SUBST_FILES.fix-info=		doc/interpreter/*.txi doc/liboctave/*.txi \
				doc/interpreter/*.texi doc/liboctave/*.texi \
				src/*.cc src/DLD-FUNCTIONS/*.cc src/DOCSTRINGS \
				scripts/DOCSTRINGS \
				scripts/statistics/tests/wilcoxon_test.m \
				scripts/statistics/distributions/*.m \
				scripts/audio/*.m \
				scripts/general/nextpow2.m \
				scripts/deprecated/weibcdf.m
SUBST_SED.fix-info=		-e 's:@geq{}:>=:g' -e 's:@leq{}:<=:g'

SUBST_CLASSES+=			unwrapping
SUBST_STAGE.unwrapping=		post-build
SUBST_MESSAGE.unwrapping=	Unwrapping wrapper scripts.
SUBST_FILES.unwrapping=		src/mkoctfile
SUBST_SED.unwrapping=		-e 's:$(DESTDIR)::g' -e 's:$(BUILDLINK_DIR)/lib:$(PREFIX)/lib:g'

SUBST_CLASSES+=			fix-make
SUBST_STAGE.fix-make=		post-patch
SUBST_MESSAGE.fix-make=		Fixing path to gmake.
SUBST_FILES.fix-make=		scripts/pkg/pkg.m
SUBST_SED.fix-make=		-e 's:@GMAKE@:$(GMAKE):g'

post-extract:
	find ${WRKSRC}/doc -type f -name '*.info*' -print | xargs rm -f
	mkdir ${WRKSRC}/src/pic

# substitute in the real path to various bits of the toolchain because
# mkoctfile will be used potentially by users and it needs to point at the same
# compilers as were used in building octave.  We also fix up the path to sed
# otherwise we end up with the buildlink directory in mkoctfile
post-build:
	mv ${WRKSRC}/src/mkoctfile ${WRKSRC}/src/mkoctfile.bak
	sed	-e 's;"${CC}";"${CCPATH}";g' \
		-e 's;"${CXX}";"${CXXPATH}";g' \
		-e 's;"${FC}";"${FCPATH}";g' \
		-e 's@^:[ \t]*\$${SED=.*@: \$$\{SED="${SED}"\}@g' \
		${WRKSRC}/src/mkoctfile.bak > ${WRKSRC}/src/mkoctfile
	chmod a+x ${WRKSRC}/src/mkoctfile

.include "../../audio/libsndfile/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../math/blas/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../math/lapack/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
