# $NetBSD: Makefile,v 1.10 2003/07/17 21:47:57 grant Exp $
#

DISTNAME=		Math-Pari-2.001804
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
SVR4_PKGNAME=		p5mpa
CATEGORIES=		math perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Math/}

MAINTAINER=		tech-pkg@NetBSD.org
#HOMEPAGE=
COMMENT=		perl5 interface to the pari math library

DEPENDS+=		pari-[0-9]*:../../math/pari
# XXX: to use or not to use...
#DEPENDS+=		gnuplot-[0-9]*:../../graphics/gnuplot

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Math/Pari/.packlist
TEST_TARGET=		# the tests need looking at

# XXX: could be improved...
post-extract:
	if [ ! -d ${_PKGSRCDIR}/math/pari/${WRKDIR_BASENAME} ]; then \
	  cd ${_PKGSRCDIR}/math/pari && ${MAKE}; \
	fi
	${RM} -f ${WRKSRC}/pari-*
	${LN} -sf ${_PKGSRCDIR}/math/pari/${WRKDIR_BASENAME}/pari-* ${WRKSRC}/

pre-clean:
	cd ${_PKGSRCDIR}/math/pari && ${MAKE} clean

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
