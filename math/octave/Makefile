# $NetBSD: Makefile,v 1.37 2003/09/28 18:02:16 kristerw Exp $
# FreeBSD Id: Makefile,v 1.18 1998/09/27 20:10:45 steve Exp

DISTNAME=	octave-2.0.17
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.che.wisc.edu/pub/octave/ \
		ftp://ftp.math.uni-hamburg.de/pub/soft/math/octave/ \
		ftp://ftp.eos.hokudai.ac.jp/pub/GNU/misc/octave/ \
		ftp://ftp.u-aizu.ac.jp/pub/SciEng/numanal/Octave/ \
		ftp://ftp.task.gda.pl/pub/software/octave/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.che.wisc.edu/octave/
COMMENT=	High-level language, primarily intended for numerical computations

BUILD_DEPENDS+=	teTeX{,2}>=1.0.7:../../print/teTeX
DEPENDS+=	gnuplot>=3.7:../../graphics/gnuplot

CONFLICTS+=	octave-2.1.*

USE_BUILDLINK2=		yes
USE_X11=		yes
GNU_CONFIGURE=		yes
USE_FORTRAN=		yes
USE_LIBTOOL=		yes
USE_GMAKE=		yes
CONFIGURE_ENV+=		FFLAGS="${CFLAGS}" OBJECT_FMT="${OBJECT_FMT}"
CPPFLAGS+=		-I${WRKDIR}/include
LDFLAGS+=		-Wl,${RPATH_FLAG}${PREFIX}/lib -L${PREFIX}/lib

USE_MAKEINFO=	YES
INFO_FILES=	liboctave.info octave.info
LIBOCTAVE_INFO=	liboctave.info liboctave.info-1 liboctave.info-2 liboctave.info-3

post-extract:
	${FIND} ${WRKSRC}/doc -type f -name \*.info\* | ${XARGS} ${RM} -f

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/octave/2.0.17/doc
.for file in ${LIBOCTAVE_INFO}
	${INSTALL_DATA} ${WRKSRC}/doc/liboctave/${file} ${PREFIX}/info
.endfor
	${INSTALL_DATA} ${WRKSRC}/doc/interpreter/octave.ps ${PREFIX}/share/octave/2.0.17/doc
	${INSTALL_DATA} ${WRKSRC}/doc/liboctave/liboctave.ps ${PREFIX}/share/octave/2.0.17/doc
	${INSTALL_DATA} ${WRKSRC}/doc/refcard/refcard-letter.ps ${PREFIX}/share/octave/2.0.17/doc
	${INSTALL_DATA} ${WRKSRC}/doc/refcard/refcard-legal.ps ${PREFIX}/share/octave/2.0.17/doc
	${INSTALL_DATA} ${WRKSRC}/doc/refcard/refcard-a4.ps ${PREFIX}/share/octave/2.0.17/doc
	${INSTALL_DATA} ${WRKSRC}/doc/faq/Octave-FAQ.ps ${PREFIX}/share/octave/2.0.17/doc

.include "../../mk/bsd.prefs.mk"

GCC_VERSION!=   ${CC} --version

post-patch:
.if ${GCC_VERSION:C/-.*$$//} == egcs
	@EGCS_VERSION=`${CC} -v 2>&1 | ${AWK} '{print $$4}'`; \
	if [ $$EGCS_VERSION -lt 19981201 ]; then \
		cd ${WRKSRC}; \
		for FILE in ${PATCHDIR}/egcs-patch-*; do \
		  ${PATCH} ${PATCH_ARGS} <$$FILE; \
		done; \
	fi
.endif

.include "../../mk/bsd.pkg.mk"
