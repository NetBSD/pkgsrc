# $NetBSD: Makefile,v 1.7 2001/04/24 23:43:02 jtb Exp $

DISTNAME=	tela-1.32
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.funet.fi/pub/sci/math/tela/ \
		ftp://sumppu.fmi.fi/pub/tela/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.geo.fmi.fi/prog/tela_00.html
COMMENT=	Tensor Language - a programming language for scientific computing

DEPENDS+=	blas-[0-9]*:../../math/blas
DEPENDS+=	lapack-[0-9]*:../../math/lapack
DEPENDS+=	hdf-[0-9]*:../../devel/hdf
DEPENDS+=	plotmtv-[0-9]*:../../graphics/plotmtv
DEPENDS+=	readline-[0-9]*:../../devel/readline

EVAL_PREFIX+=	BLAS_PREFIX=blas LAPACK_PREFIX=lapack
EVAL_PREFIX+=	HDF_PREFIX=hdf JPEG_PREFIX=jpeg
EVAL_PREFIX+=	READLINE_PREFIX=readline

GNU_CONFIGURE=	#defined
USE_FORTRAN=	#defined
USE_X11=	#defined

INSTALL_TARGET= install installdocs

CONFIGURE_ENV+=	"INSTALLATION_PREFIX=${PREFIX}/share/tela"
CONFIGURE_ENV+=	"ARCHDEP_INSTALLATION_PREFIX=${PREFIX}/lib/tela"

pre-configure:
	@for f in ${WRKSRC}/t/demo.t ${WRKSRC}/t/docview.t	\
	${WRKSRC}/t/std.t; do					\
		${SED} -e 's:@PREFIX@:'${PREFIX}':g'		\
		$$f > $$f.tmp && ${MV} -f $$f.tmp $$f;		\
	done

.include "../../mk/bsd.pkg.mk"
