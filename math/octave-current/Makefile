# $NetBSD: Makefile,v 1.24 2003/12/04 11:15:37 adam Exp $
#

DISTNAME=	octave-${OCTAVE_VER}
PKGNAME=	octave-current-${OCTAVE_VER}
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.che.wisc.edu/pub/octave/bleeding-edge/ \
		ftp://ftp.eos.hokudai.ac.jp/pub/GNU/misc/octave/bleeding-edge/ \
		ftp://ftp.u-aizu.ac.jp/pub/SciEng/numanal/Octave/bleeding-edge/ \
		ftp://ftp.task.gda.pl/pub/software/octave/bleeding-edge/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	adam@netbsd.org
HOMEPAGE=	http://www.che.wisc.edu/octave/
COMMENT=	High-level language, intended for numerical computations

BUILD_DEPENDS+=	bison>=1.875:../../devel/bison
BUILD_DEPENDS+=	gperf>=2.7:../../devel/gperf
DEPENDS+=	gnuplot>=3.7:../../graphics/gnuplot

OCTAVE_VER=	2.1.52
CONFLICTS+=	octave-2.0.*

.if (${MACHINE_ARCH} == "arm32")
BROKEN=		Internal compiler error occurs on arm32 (even with gcc-2.95.3)
.endif

USE_BUILDLINK2=		YES
USE_FORTRAN=		YES
USE_GMAKE=		YES
USE_GNU_READLINE=	YES
USE_MAKEINFO=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
GNU_CONFIGURE=		YES

INFO_FILES=	octave.info liboctave.info
LIBOCTAVE_INFO=	liboctave.info liboctave.info-1 \
		liboctave.info-2 liboctave.info-3
OCTAVE_DOC=	faq/Octave-FAQ.ps interpreter/octave.ps \
		liboctave/liboctave.ps refcard/refcard-a4.ps \
		refcard/refcard-legal.ps  refcard/refcard-letter.ps
OCTAVE_HTML=	faq/Octave-FAQ_*.html interpreter/octave_*.html \
		liboctave/liboctave_*.html

post-extract:
	${FIND} ${WRKSRC}/doc -type f -name '*.info*' -exec ${RM} -f {} \;

post-install:
.for f in ${LIBOCTAVE_INFO}
	${INSTALL_DATA} ${WRKSRC}/doc/liboctave/$f ${PREFIX}/info
.endfor
	${INSTALL_DATA_DIR} ${PREFIX}/share/octave/${OCTAVE_VER}/doc
.for f in ${OCTAVE_DOC}
	${INSTALL_DATA} ${WRKSRC}/doc/$f ${PREFIX}/share/octave/${OCTAVE_VER}/doc
.endfor
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/octave
.for f in ${OCTAVE_HTML}
	${INSTALL_DATA} ${WRKSRC}/doc/$f ${PREFIX}/share/doc/html/octave
.endfor

.include "../../audio/libsndfile/buildlink2.mk"
.include "../../devel/readline/buildlink2.mk"
.include "../../devel/ncurses/buildlink2.mk"
.include "../../math/blas/buildlink2.mk"
.include "../../math/fftw2/buildlink2.mk"
.include "../../math/lapack/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
