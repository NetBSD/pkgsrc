# $NetBSD: Makefile,v 1.1.1.1 2001/02/28 22:34:05 jtb Exp $

DISTNAME=	tela-1.30
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.funet.fi/pub/sci/math/tela/ \
		ftp://sumppu.fmi.fi/pub/tela/

MAINTAINER=	jtb@netbsd.org
HOMEPAGE=	http://www.geo.fmi.fi/prog/tela_00.html
COMMENT=	Tensor Language - a programming language for scientific computing

DEPENDS+=	blas-[0-9]*:../../math/blas
DEPENDS+=	lapack-[0-9]*:../../math/lapack
DEPENDS+=	hdf-[0-9]*:../../devel/hdf
DEPENDS+=	plotmtv-[0-9]*:../../graphics/plotmtv
DEPENDS+=	readline-[0-9]*:../../devel/readline

EVAL_PREFIX+=	HDF_PREFIX=hdf F2C_PREFIX=f2c
EVAL_PREFIX+=	READLINE_PREFIX=readline JPEG_PREFIX=jpeg
EVAL_PREFIX+=	BLAS_PREFIX=blas LAPACK_PREFIX=lapack

GNU_CONFIGURE=	#defined
USE_FORTRAN=	#defined
USE_X11=	#defined

INSTALL_TARGET= install installdocs

CONFIGURE_ENV+=	"INSTALLATION_PREFIX=${PREFIX}/share/tela"
CONFIGURE_ENV+=	"ARCHDEP_INSTALLATION_PREFIX=${PREFIX}/lib/tela"

pre-configure:
	@for f in ${WRKSRC}/telakka.in ${WRKSRC}/t/demo.t	\
	${WRKSRC}/t/docview.t ${WRKSRC}/t/std.t; do		\
		${SED} -e 's:@PREFIX@:'${PREFIX}':g'		\
		< $$f > $$f.tmp && ${MV} -f $$f.tmp $$f;	\
	done

.include "../../mk/bsd.pkg.mk"
