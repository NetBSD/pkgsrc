# $NetBSD: Makefile,v 1.13 2004/04/27 21:26:08 snj Exp $
#

DISTNAME=		Math-Pari-2.010501
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		# empty
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
USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Math/Pari/.packlist
#TEST_TARGET=		# the tests need looking at

# XXX: could be improved...
post-extract:
	if [ ! -d ${_PKGSRCDIR}/math/pari/${WRKDIR_BASENAME} ]; then \
	  cd ${_PKGSRCDIR}/math/pari && ${MAKE} configure; \
	fi
	${RM} -f ${WRKSRC}/pari-*
	${LN} -sf ${_PKGSRCDIR}/math/pari/${WRKDIR_BASENAME}/pari-* ${WRKSRC}/

pre-clean:
	cd ${_PKGSRCDIR}/math/pari && ${MAKE} clean

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
