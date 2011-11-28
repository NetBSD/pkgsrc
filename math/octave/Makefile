# $NetBSD: Makefile,v 1.93 2011/11/28 22:51:27 drochner Exp $

DISTNAME=	octave-${OCTAVE_VER}
PKGREVISION=	5
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.octave.org/pub/octave/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.octave.org/
COMMENT=	High-level language, intended for numerical computations

BUILD_DEPENDS+=	bison>=1.875:../../devel/bison
BUILD_DEPENDS+=	gperf>=2.7:../../devel/gperf
DEPENDS+=	gnuplot>=3.7:../../graphics/gnuplot

OCTAVE_VER=	3.2.4
CONFLICTS+=	octave-2.*

.if (${MACHINE_ARCH} == "arm32")
BROKEN=		Internal compiler error occurs on arm32 (even with gcc-2.95.3)
.endif

PKG_DESTDIR_SUPPORT=	user-destdir

USE_GNU_READLINE=	yes
USE_TOOLS+=		autoconf gsed gmake makeinfo perl pkg-config
GNU_CONFIGURE=		yes
MAKE_JOBS_SAFE=		no

GCC_REQD+=		3.0
USE_LANGUAGES=		c c++ fortran77

# needed for loading of shared objects such as those in the
# octave-forge package or user written ones compiled with mkoctfile
CONFIGURE_ARGS+=	--enable-dl
CONFIGURE_ARGS+=	--enable-static
CONFIGURE_ARGS+=	--enable-shared

# trick pkgsrc into real gsed, needed for "mkf77def"
TOOLS_PLATFORM.gsed=	#empty

.include "options.mk"

GNU_PLATFORM_DIR!=	${.CURDIR}/../../mk/gnu-config/config.sub ${MACHINE_GNU_PLATFORM}
PLIST_SUBST+=		GNU_PLATFORM_DIR=${GNU_PLATFORM_DIR}

INFO_FILES=	yes
OCTAVE_DOC=	faq/Octave-FAQ.ps  liboctave/liboctave.ps \
		refcard/refcard-a4.ps refcard/refcard-legal.ps \
		refcard/refcard-letter.ps

INSTALLATION_DIRS+=	share/octave/${OCTAVE_VER}/doc
UNWRAP_FILES+=		mkoctfile octave-bug src/oct-conf.h

# Doesn't work yet, needs to sort out libtool shared libraries handling:
#TEST_TARGET=	check

pre-configure:
	cd ${WRKSRC} && autoconf

post-extract:
	find ${WRKSRC}/doc -type f -name '*.info*' -print | xargs rm -f
	mkdir ${WRKSRC}/src/pic

# substitute in the real path to various bits of the toolchain because
# mkoctfile will be used potentially by users and it needs to point at the same
# compilers as were used in building octave.  We also fix up the path to sed
# otherwise we end up with the buildlink directory in mkoctfile
post-build:
	mv ${WRKSRC}/mkoctfile ${WRKSRC}/mkoctfile.bak
	sed	-e 's;"${CC}";"${CCPATH}";g' \
		-e 's;"${CXX}";"${CXXPATH}";g' \
		-e 's;"${FC}";"${FCPATH}";g' \
		-e 's@^:[ \t]*\$${SED=.*@: \$$\{SED="${SED}"\}@g' \
		${WRKSRC}/mkoctfile.bak > ${WRKSRC}/mkoctfile
	chmod a+x ${WRKSRC}/mkoctfile
	(cd ${WRKSRC}/doc/interpreter && gmake octave.ps)

post-install:
	cd ${WRKSRC}/doc/liboctave;					\
	for f in liboctave.info liboctave.info-[0-9]*; do		\
		${TEST} ! -f "$$f" ||					\
		${INSTALL_DATA} "$$f" ${DESTDIR}${PREFIX}/${PKGINFODIR};		\
	done
.for f in ${OCTAVE_DOC}
	${INSTALL_DATA} ${WRKSRC}/doc/${f} ${DESTDIR}${PREFIX}/share/octave/${OCTAVE_VER}/doc
.endfor

.include "../../audio/libsndfile/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../math/blas/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../math/lapack/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
