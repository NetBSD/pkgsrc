# $NetBSD: Makefile,v 1.15 2004/04/27 21:26:09 snj Exp $

DISTNAME=		tela-1.34
CATEGORIES=		math
MASTER_SITES=		ftp://ftp.funet.fi/pub/sci/math/tela/ \
			ftp://sumppu.fmi.fi/pub/tela/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.geo.fmi.fi/prog/tela_00.html
COMMENT=		Tensor Language - a programming language for scientific computing

DEPENDS+=		plotmtv-[0-9]*:../../graphics/plotmtv

GNU_CONFIGURE=		# defined
USE_FORTRAN=		# defined
USE_X11=		# defined
USE_BUILDLINK3=		yes

INSTALL_TARGET= 	install installdocs

CONFIGURE_ENV+=		INSTALLATION_PREFIX=${PREFIX}/share/tela
CONFIGURE_ENV+=		ARCHDEP_INSTALLATION_PREFIX=${PREFIX}/lib/tela

pre-configure:
	@for f in ${WRKSRC}/t/demo.t ${WRKSRC}/t/docview.t	\
	${WRKSRC}/t/std.t; do					\
		${SED} -e 's:@PREFIX@:'${PREFIX}':g'		\
		$$f > $$f.tmp && ${MV} -f $$f.tmp $$f;		\
	done

.include "../../math/lapack/buildlink3.mk"
.include "../../math/blas/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/hdf/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
