# $NetBSD: Makefile,v 1.64 2007/12/02 11:21:38 wiz Exp $

DISTNAME=	octave-${OCTAVE_VER}
PKGNAME=	octave-current-${OCTAVE_VER}
PKGREVISION=	1
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.che.wisc.edu/pub/octave/bleeding-edge/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.octave.org/
COMMENT=	High-level language, intended for numerical computations

BUILD_DEPENDS+=	bison>=1.875:../../devel/bison
BUILD_DEPENDS+=	gperf>=2.7:../../devel/gperf
DEPENDS+=	gnuplot>=3.7:../../graphics/gnuplot

OCTAVE_VER=	2.9.14
CONFLICTS+=	octave-2.*

.if (${MACHINE_ARCH} == "arm32")
BROKEN=		Internal compiler error occurs on arm32 (even with gcc-2.95.3)
.endif

USE_GNU_READLINE=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake makeinfo perl gsed
GNU_CONFIGURE=		yes
USE_DIRS+=		xdg-1.1

GCC_REQD+=		3.0
USE_LANGUAGES=		c c++ fortran

# needed for loading of shared objects such as those in the
# octave-forge package or user written ones compiled with mkoctfile
CONFIGURE_ARGS+=	--enable-dl
# shared libraries are handled automatically in pkgsrc
CONFIGURE_ARGS+=	--enable-static
CONFIGURE_ARGS+=	--disable-shared

# trick pkgsrc into real gsed, needed for "mkf77def"
TOOLS_PLATFORM.gsed=	#empty

.include "options.mk"

GNU_PLATFORM_DIR!=	${.CURDIR}/../../mk/gnu-config/config.sub ${MACHINE_GNU_PLATFORM}
PLIST_SUBST+=		GNU_PLATFORM_DIR=${GNU_PLATFORM_DIR:Q}

INFO_FILES=	# PLIST
OCTAVE_DOC=	faq/Octave-FAQ.ps interpreter/octave.ps \
		liboctave/liboctave.ps refcard/refcard-a4.ps \
		refcard/refcard-legal.ps  refcard/refcard-letter.ps

UNWRAP_FILES+=	mkoctfile octave-bug src/oct-conf.h

post-extract:
	${FIND} ${WRKSRC}/doc -type f -name '*.info*' -print | ${XARGS} ${RM} -f
	${MKDIR} ${WRKSRC}/src/pic

# substitute in the real path to various bits of the toolchain because
# mkoctfile will be used potentially by users and it needs to point at the same
# compilers as were used in building octave.  We also fix up the path to sed
# otherwise we end up with the buildlink directory in mkoctfile
post-build:
	${MV} ${WRKSRC}/mkoctfile ${WRKSRC}/mkoctfile.bak
	${SED}	-e 's;"${CC}";"${CCPATH}";g' \
		-e 's;"${CXX}";"${CXXPATH}";g' \
		-e 's;"${FC}";"${FCPATH}";g' \
		-e 's@^:[ \t]*\$${SED=.*@: \$$\{SED="${SED}"\}@g' \
		${WRKSRC}/mkoctfile.bak > ${WRKSRC}/mkoctfile
	${CHMOD} a+x ${WRKSRC}/mkoctfile
	(cd ${WRKSRC}/doc/interpreter && ${GMAKE} octave.ps)

post-install:
	cd ${WRKSRC}/doc/liboctave;					\
	for f in liboctave.info liboctave.info-[0-9]*; do		\
		${TEST} ! -f "$$f" ||					\
		${INSTALL_DATA} "$$f" ${PREFIX}/${PKGINFODIR};		\
	done
	${INSTALL_DATA_DIR} ${PREFIX}/share/octave/${OCTAVE_VER}/doc
.for f in ${OCTAVE_DOC}
	${INSTALL_DATA} ${WRKSRC}/doc/${f} ${PREFIX}/share/octave/${OCTAVE_VER}/doc
.endfor

.include "../../audio/libsndfile/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../math/blas/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../math/lapack/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
