# $NetBSD: Makefile,v 1.7 2002/10/27 21:20:37 seb Exp $
#

DISTNAME=		Math-Pari-2.001804
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
SVR4_PKGNAME=		p5mpa
CATEGORIES=		math perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Math/}

MAINTAINER=		packages@netbsd.org
#HOMEPAGE=	
COMMENT=		perl5 interface to the pari math library

DEPENDS+=		pari-[0-9]*:../../math/pari
# XXX: to use or not to use...
#DEPENDS+=		gnuplot-[0-9]*:../../graphics/gnuplot

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Math/Pari/.packlist

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
