# $NetBSD: Makefile,v 1.17 2005/05/02 14:26:53 seb Exp $
#

DISTNAME=		Math-Pari-2.010501
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
SVR4_PKGNAME=		p5mpa
CATEGORIES=		math perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Math/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Math-Pari/
COMMENT=		Perl5 interface to the pari math library

# XXX: to use or not to use...
#DEPENDS+=		gnuplot-[0-9]*:../../graphics/gnuplot

GCC_REQD=		2.95
MAKE_ENV+=		MP_NOGNUPLOT=1
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Math/Pari/.packlist
#TEST_TARGET=		# the tests need looking at

# XXX: could be improved...
post-extract:
	if [ ! -d ${PKGSRCDIR}/math/pari/${WRKDIR_BASENAME} ]; then \
	  cd ${PKGSRCDIR}/math/pari && ${MAKE} configure; \
	fi
	${RM} -f ${WRKSRC}/pari-*
	${LN} -sf ${PKGSRCDIR}/math/pari/${WRKDIR_BASENAME}/pari-* ${WRKSRC}/

pre-clean:
	cd ${PKGSRCDIR}/math/pari && ${MAKE} clean

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
