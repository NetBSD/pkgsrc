# $NetBSD: Makefile,v 1.131 2016/02/03 16:07:53 nros Exp $

DISTNAME=	octave-${OCTAVE_VER}
PKGREVISION=	12
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GNU:=octave/}
MASTER_SITES+=	ftp://ftp.octave.org/pub/octave/
MASTER_SITES+=	ftp://ftp.octave.org/pub/octave/bleeding-edge/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.octave.org/
COMMENT=	High-level language, intended for numerical computations
LICENSE=	gnu-gpl-v3

BUILD_DEPENDS+=	gperf>=2.7:../../devel/gperf
BUILD_DEPENDS+=	tex-latex-fonts-[0-9]*:../../fonts/tex-latex-fonts
BUILD_DEPENDS+=	dvipsk-[0-9]*:../../print/dvipsk
BUILD_DEPENDS+=	tex-epsf-[0-9]*:../../print/tex-epsf
BUILD_DEPENDS+=	tex-tex-[0-9]*:../../print/tex-tex
BUILD_DEPENDS+=	tex-pdftex-[0-9]*:../../print/tex-pdftex
TOOL_DEPENDS+=	gtexinfo>=5.1:../../devel/gtexinfo
DEPENDS+=	gnuplot>=3.7:../../graphics/gnuplot

OCTAVE_VER=	3.6.4

.if (${MACHINE_ARCH} == "arm32")
BROKEN=		Internal compiler error occurs on arm32 (even with gcc-2.95.3)
.endif

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

CONFIGURE_ARGS+=	--without-opengl

# We use this to install .oct files so it doesn't strip them.
CONFIGURE_ENV+=		INSTALL_LIB=${INSTALL_LIB:Q}

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
SUBST_SED.unwrapping=		-e 's:$(DESTDIR)::g'
SUBST_SED.unwrapping+=		-e 's:$(BUILDLINK_DIR)/lib:$(PREFIX)/lib:g'

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
