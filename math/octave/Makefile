# $NetBSD: Makefile,v 1.2 1998/11/25 23:56:53 tron Exp $
# FreeBSD Id: Makefile,v 1.18 1998/09/27 20:10:45 steve Exp
#

DISTNAME=	octave-2.0.13
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.che.wisc.edu/pub/octave/ \
		ftp://ftp.math.uni-hamburg.de/pub/soft/math/octave/ \
		ftp://ftp.eos.hokudai.ac.jp/pub/GNU/misc/octave/ \
		ftp://ftp.u-aizu.ac.jp/pub/SciEng/numanal/Octave/ \
		ftp://ftp.task.gda.pl/pub/software/octave/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.che.wisc.edu/octave/

BUILD_DEPENDS+=	makeinfo:../../devel/gtexinfo
BUILD_DEPENDS+=	tex:../../print/teTeX
BUILD_DEPENDS+=	dvips:../../print/teTeX
DEPENDS+=	ncurses-1.9.9g:../../devel/ncurses
DEPENDS+=	f2c-19980516p1:../../lang/f2c
DEPENDS+=	gnuplot-3.5:../../graphics/gnuplot

BROKEN_ELF=	build

HAS_CONFIGURE=	yes
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_GMAKE=	yes
CONFIGURE_ENV=	PATH="${PATH}"

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

.include <../../mk/bsd.pkg.mk>
