# $NetBSD: Makefile,v 1.13 1999/12/16 15:42:54 dmcmahill Exp $
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
DEPENDS+=	gnuplot-3.7:../../graphics/gnuplot

USE_X11=		yes
GNU_CONFIGURE=		yes
USE_FORTRAN=		yes
USE_LIBTOOL=		yes
USE_GMAKE=		yes
CONFIGURE_ENV+=		CPPFLAGS=-I${WRKDIR}/include
LDFLAGS+=		-Wl,-R${PREFIX}/lib -L${PREFIX}/lib

INFO_FILES=	liboctave.info octave.info
LIBOCTAVE_INFO=	liboctave.info liboctave.info-1 liboctave.info-2 liboctave.info-3

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

.include "../../mk/bsd.prefs.mk"

GCC_VERSION!=	${CC} --version 

post-patch:
.if (${GCC_VERSION:C/-.*$$//} == egcs)
	@cd ${WRKSRC};
	for FILE in ${PATCHDIR}/egcs-patch-*; do \
	  ${PATCH} ${PATCH_ARGS} <$$FILE; \
	done
.endif

.include "../../mk/bsd.pkg.mk"
