# $NetBSD: Makefile,v 1.1.1.1 2001/03/27 12:06:55 wennmach Exp $

DISTNAME=	octave-2.1.33
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.che.wisc.edu/pub/octave/bleeding-edge/ \
		ftp://ftp.math.uni-hamburg.de/pub/soft/math/octave/bleeding-edge/ \
		ftp://ftp.eos.hokudai.ac.jp/pub/GNU/misc/octave/bleeding-edge/ \
		ftp://ftp.u-aizu.ac.jp/pub/SciEng/numanal/Octave/bleeding-edge/ \
		ftp://ftp.task.gda.pl/pub/software/octave/bleeding-edge/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.che.wisc.edu/octave/
COMMENT=	A high-level language, primarily intended for numerical computations

DEPENDS+=	gnuplot>=3.7:../../graphics/gnuplot
DEPENDS+=	readline>=4.0:../../devel/readline

CONFLICTS=	octave-2.0.*

USE_X11=	yes
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_GMAKE=	yes
USE_GTEXINFO=	yes
CONFIGURE_ARGS+=--with-g77 --enable-shared --enable-rpath
CONFIGURE_ARGS+=-prefix=${PREFIX}

CONFIGURE_ENV+=	FFLAGS="${CFLAGS}" OBJECT_FMT="${OBJECT_FMT}"
LDFLAGS+=	-L${PREFIX}/lib
LTCONFIG_OVERRIDE=${WRKSRC}/ltconfig

INFO_FILES=	octave.info liboctave.info
LIBOCTAVE_INFO=	liboctave.info liboctave.info-1 \
		liboctave.info-2 liboctave.info-3
OCTAVE_DOC=	faq/Octave-FAQ.ps faq/Octave-FAQ_toc.html \
		interpreter/octave.ps interpreter/octave_*.html \
		liboctave/liboctave.ps liboctave/liboctave_*.html \
		refcard/refcard-a4.ps refcard/refcard-legal.ps \
		refcard/refcard-letter.ps

post-install:
	${MKDIR} ${PREFIX}/share/octave/doc
.for file in ${LIBOCTAVE_INFO}
	${INSTALL_DATA} ${WRKSRC}/doc/liboctave/${file} ${PREFIX}/info
.endfor
.for file in ${OCTAVE_DOC}
	${INSTALL_DATA} ${WRKSRC}/doc/${file} ${PREFIX}/share/octave/doc
.endfor

.include <../../mk/bsd.pkg.mk>
