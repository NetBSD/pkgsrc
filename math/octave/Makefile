# $NetBSD: Makefile,v 1.7 1999/01/14 13:57:04 frueauf Exp $
# FreeBSD Id: Makefile,v 1.18 1998/09/27 20:10:45 steve Exp

DISTNAME=	octave-2.0.13
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.che.wisc.edu/pub/octave/ \
		ftp://ftp.math.uni-hamburg.de/pub/soft/math/octave/ \
		ftp://ftp.eos.hokudai.ac.jp/pub/GNU/misc/octave/ \
		ftp://ftp.u-aizu.ac.jp/pub/SciEng/numanal/Octave/ \
		ftp://ftp.task.gda.pl/pub/software/octave/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.che.wisc.edu/octave/

BUILD_DEPENDS+=	tex:../../print/teTeX
BUILD_DEPENDS+=	dvips:../../print/teTeX
DEPENDS+=	ncurses-1.9.9g:../../devel/ncurses
DEPENDS+=	gnuplot-3.5:../../graphics/gnuplot

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_GMAKE=		yes
CONFIGURE_ENV+=		CPPFLAGS=-I${WRKDIR}/include
LDFLAGS+=		-L${PREFIX}/lib

INFO_FILES=	liboctave.info octave.info
LIBOCTAVE_INFO=	liboctave.info liboctave.info-1 liboctave.info-2 liboctave.info-3

post-extract:
	${MKDIR} ${WRKDIR}/include
	${LN} -s ${PREFIX}/include/ncurses.h ${WRKDIR}/include

post-install:
	${MKDIR} ${PREFIX}/share/octave/2.0.13/doc
.for file in ${LIBOCTAVE_INFO}
	${INSTALL_DATA} ${WRKSRC}/doc/liboctave/${file} ${PREFIX}/info
.endfor
	${INSTALL_DATA} ${WRKSRC}/doc/interpreter/octave.ps ${PREFIX}/share/octave/2.0.13/doc
	${INSTALL_DATA} ${WRKSRC}/doc/liboctave/liboctave.ps ${PREFIX}/share/octave/2.0.13/doc
	${INSTALL_DATA} ${WRKSRC}/doc/refcard/refcard-letter.ps ${PREFIX}/share/octave/2.0.13/doc
	${INSTALL_DATA} ${WRKSRC}/doc/refcard/refcard-legal.ps ${PREFIX}/share/octave/2.0.13/doc
	${INSTALL_DATA} ${WRKSRC}/doc/refcard/refcard-a4.ps ${PREFIX}/share/octave/2.0.13/doc
	${INSTALL_DATA} ${WRKSRC}/doc/faq/Octave-FAQ.ps ${PREFIX}/share/octave/2.0.13/doc

GCC_VERSION!=	${CC} --version

.if (${GCC_VERSION:C/-.*$$//} == egcs)
CONFIGURE_ARGS+=	--with-g77
FLIBS=			-Lg2c
.else
DEPENDS+=		f2c-19980913:../../lang/f2c
CONFIGURE_ARGS+=	--with-f2c
.endif

post-patch:
.if (${GCC_VERSION:C/-.*$$//} == egcs)
	@cd ${WRKSRC};
	for FILE in ${PATCHDIR}/egcs-patch-*; do \
	  ${PATCH} ${PATCH_ARGS} <$$FILE; \
	done
.endif

.include <../../mk/bsd.pkg.mk>
