# $NetBSD: Makefile,v 1.6 2001/10/18 15:20:14 veego Exp $
#

DISTNAME=		Devel-SmallProf-0.9
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5dsp
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=		bad@netbsd.org
COMMENT=		perl5 module for line-by-line profiling perl programs

DEPENDS=		p5-Time-HiRes>=01.20:../../devel/p5-Time-HiRes

USE_PERL5=		# defined
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Devel/SmallProf/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
