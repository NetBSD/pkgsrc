# $NetBSD: Makefile,v 1.23 2003/09/28 17:54:14 kristerw Exp $

DISTNAME=	octave-2.1.33
PKGNAME=	octave-2.1.34
PKGREVISION=	1
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.che.wisc.edu/pub/octave/bleeding-edge/ \
		ftp://ftp.eos.hokudai.ac.jp/pub/GNU/misc/octave/bleeding-edge/ \
		ftp://ftp.u-aizu.ac.jp/pub/SciEng/numanal/Octave/bleeding-edge/ \
		ftp://ftp.task.gda.pl/pub/software/octave/bleeding-edge/
EXTRACT_SUFX=	.tar.bz2

PATCHFILES=	octave-2.1.33-2.1.34.patch.gz
PATCH_SITES=	${MASTER_SITES}
PATCH_DIST_STRIP= -p1

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.che.wisc.edu/octave/
COMMENT=	High-level language, primarily intended for numerical computations

BUILD_DEPENDS+= teTeX{,2}>=1.0.7:../../print/teTeX
DEPENDS+=	gnuplot>=3.7:../../graphics/gnuplot

.if ${MACHINE_ARCH} == "arm" || ${MACHINE_ARCH} == "arm32"
GCC_REQD=	3.0
.endif

USE_X11=	yes
USE_BUILDLINK2=	yes
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_FORTRAN=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS+=--with-g77
CONFIGURE_ARGS+=--enable-shared --enable-rpath
CONFIGURE_ARGS+=-prefix=${PREFIX}

CONFIGURE_ENV+=	FFLAGS="${CFLAGS}" OBJECT_FMT="${OBJECT_FMT}"
LTCONFIG_OVERRIDE=${WRKSRC}/ltconfig

USE_GNU_READLINE=		# defined
BUILDLINK_DEPENDS.readline=	readline>=4.0
LDFLAGS+=	-L${BUILDLINK_PREFIX.readline}/lib

USE_MAKEINFO=	YES
INFO_FILES=	octave.info liboctave.info
LIBOCTAVE_INFO=	liboctave.info liboctave.info-1 \
		liboctave.info-2 liboctave.info-3
OCTAVE_DOC=	faq/Octave-FAQ.ps interpreter/octave.ps \
		liboctave/liboctave.ps refcard/refcard-a4.ps \
		refcard/refcard-legal.ps  refcard/refcard-letter.ps
OCTAVE_HTML=	faq/Octave-FAQ_toc.html interpreter/octave_*.html \
		interpreter/octave.html liboctave/liboctave_*.html

post-patch:
	@cd ${WRKSRC}/libcruft/misc && ${RM} -f xstopx.f dostop.c

post-install:
.for f in ${LIBOCTAVE_INFO}
	${INSTALL_DATA} ${WRKSRC}/doc/liboctave/$f ${PREFIX}/info
.endfor
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/octave
.for f in ${OCTAVE_DOC}
	${INSTALL_DATA} ${WRKSRC}/doc/$f ${PREFIX}/share/doc/octave
.endfor
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/octave
.for f in ${OCTAVE_HTML}
	${INSTALL_DATA} ${WRKSRC}/doc/$f ${PREFIX}/share/doc/html/octave
.endfor

.include "../../devel/readline/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
