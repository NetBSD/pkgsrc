# $NetBSD: Makefile,v 1.2 2001/10/03 02:41:41 hubertf Exp $
#

DISTNAME=		Math-Pari-2.001804
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		math perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Math/}

MAINTAINER=		packages@netbsd.org
#HOMEPAGE=	
COMMENT=		perl5 interface to the pari math library

DEPENDS+=		pari-[0-9]*:../../math/pari
# XXX: to use or not to use...
#DEPENDS+=		gnuplot-[0-9]*:../../graphics/gnuplot

USE_PERL5=		# defined
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Math/Pari/.packlist

# XXX: could be improved...
post-extract:
	if [ ! -d ${BUILD_ROOT}/math/pari/${WRKDIR_BASENAME} ]; then \
	  cd ${BUILD_ROOT}/math/pari && ${MAKE}; \
	fi
	${RM} -f ${WRKSRC}/pari-*
	${LN} -sf ${BUILD_ROOT}/math/pari/${WRKDIR_BASENAME}/pari-* ${WRKSRC}/

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
