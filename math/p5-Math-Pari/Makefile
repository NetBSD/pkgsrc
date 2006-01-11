# $NetBSD: Makefile,v 1.22 2006/01/11 21:24:09 joerg Exp $
#

DISTNAME=		Math-Pari-2.010501
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
SVR4_PKGNAME=		p5mpa
CATEGORIES=		math perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Math/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Math-Pari/
COMMENT=		Perl5 interface to the pari math library

# XXX: to use or not to use...
#DEPENDS+=		gnuplot-[0-9]*:../../graphics/gnuplot

GCC_REQD+=		2.95
MAKE_ENV+=		MP_NOGNUPLOT=1
PERL5_PACKLIST=		auto/Math/Pari/.packlist
#TEST_TARGET=		# the tests need looking at

# XXX: could be improved...
PKGSRCDIR.pari=		${.CURDIR}/../../math/pari
WRKSRC.pari_cmd=		\
	cd ${PKGSRCDIR.pari} && ${MAKE} show-var VARNAME=WRKSRC

post-extract:
	cd ${PKGSRCDIR.pari:Q} && ${MAKE} configure;		\
	${RM} -f ${WRKSRC}/pari-*
	${LN} -sf ${WRKSRC.pari_cmd:sh:Q} ${WRKSRC}

pre-clean:
	cd ${PKGSRCDIR.pari:Q} && ${MAKE} clean

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
