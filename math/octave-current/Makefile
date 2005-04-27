# $NetBSD: Makefile,v 1.47 2005/04/27 14:31:05 adam Exp $

DISTNAME=	octave-${OCTAVE_VER}
PKGNAME=	octave-current-${OCTAVE_VER}
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.che.wisc.edu/pub/octave/bleeding-edge/ \
		ftp://ftp.eos.hokudai.ac.jp/pub/GNU/misc/octave/bleeding-edge/ \
		ftp://ftp.u-aizu.ac.jp/pub/SciEng/numanal/Octave/bleeding-edge/ \
		ftp://ftp.task.gda.pl/pub/software/octave/bleeding-edge/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.che.wisc.edu/octave/
COMMENT=	High-level language, intended for numerical computations

BUILD_DEPENDS+=	bison>=1.875:../../devel/bison
BUILD_DEPENDS+=	gperf>=2.7:../../devel/gperf
DEPENDS+=	gnuplot>=3.7:../../graphics/gnuplot

OCTAVE_VER=	2.9.2
CONFLICTS+=	octave-2.*

.if (${MACHINE_ARCH} == "arm32")
BROKEN=		Internal compiler error occurs on arm32 (even with gcc-2.95.3)
.endif

USE_GNU_READLINE=	yes
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		yes
USE_MAKEINFO=		yes
USE_PERL5=		build
GNU_CONFIGURE=		yes

GCC_REQD=		3.0
USE_LANGUAGES=		c c++ fortran

# needed for loading of shared objects such as those in the
# octave-forge package or user written ones compiled with mkoctfile
CONFIGURE_ARGS+=	--enable-dl
# shared libraries are handled automatically in pkgsrc
CONFIGURE_ARGS+=	--enable-static
CONFIGURE_ARGS+=	--disable-shared

.include "options.mk"

INFO_FILES=	octave.info liboctave.info
LIBOCTAVE_INFO=	liboctave.info liboctave.info-1 \
		liboctave.info-2 liboctave.info-3
OCTAVE_DOC=	faq/Octave-FAQ.ps interpreter/octave.ps \
		liboctave/liboctave.ps refcard/refcard-a4.ps \
		refcard/refcard-legal.ps  refcard/refcard-letter.ps
OCTAVE_HTML=	faq/Octave-FAQ_*.html interpreter/octave_*.html \
		liboctave/liboctave_*.html

UNWRAP_FILES+=	mkoctfile octave-bug src/oct-conf.h

post-extract:
	${FIND} ${WRKSRC}/doc -type f -name '*.info*' -exec ${RM} -f {} \;
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

post-install:
.for f in ${LIBOCTAVE_INFO}
	${INSTALL_DATA} ${WRKSRC}/doc/liboctave/${f} ${PREFIX}/info
.endfor
	${INSTALL_DATA_DIR} ${PREFIX}/share/octave/${OCTAVE_VER}/doc
.for f in ${OCTAVE_DOC}
	${INSTALL_DATA} ${WRKSRC}/doc/${f} ${PREFIX}/share/octave/${OCTAVE_VER}/doc
.endfor
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/octave
.for f in ${OCTAVE_HTML}
	${INSTALL_DATA} ${WRKSRC}/doc/${f} ${PREFIX}/share/doc/html/octave
.endfor

.include "../../audio/libsndfile/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../math/blas/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../math/lapack/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
