# $NetBSD: Makefile,v 1.10.2.1 2002/06/23 18:52:48 jlam Exp $

DISTNAME=		tela-1.34
CATEGORIES=		math
MASTER_SITES=		ftp://ftp.funet.fi/pub/sci/math/tela/ \
			ftp://sumppu.fmi.fi/pub/tela/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.geo.fmi.fi/prog/tela_00.html
COMMENT=		Tensor Language - a programming language for scientific computing

DEPENDS+=		plotmtv-[0-9]*:../../graphics/plotmtv

GNU_CONFIGURE=		# defined
USE_FORTRAN=		# defined
USE_X11=		# defined
USE_BUILDLINK_ONLY=	# defined
REPLACE_BUILDLINK=	${WRKSRC}/telakka

INSTALL_TARGET= 	install installdocs

CONFIGURE_ENV+=		INSTALLATION_PREFIX=${PREFIX}/share/tela
CONFIGURE_ENV+=		ARCHDEP_INSTALLATION_PREFIX=${PREFIX}/lib/tela

pre-configure:
	@for f in ${WRKSRC}/t/demo.t ${WRKSRC}/t/docview.t	\
	${WRKSRC}/t/std.t; do					\
		${SED} -e 's:@PREFIX@:'${PREFIX}':g'		\
		$$f > $$f.tmp && ${MV} -f $$f.tmp $$f;		\
	done

.include "../../math/lapack/buildlink.mk"
.include "../../math/blas/buildlink.mk"
.include "../../devel/readline/buildlink.mk"
.include "../../devel/hdf/buildlink.mk"
.include "../../devel/zlib/buildlink.mk"
.include "../../graphics/jpeg/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
