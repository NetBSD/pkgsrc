# $NetBSD: Makefile,v 1.2 2005/04/11 21:45:35 tv Exp $
#

DISTNAME=		Test-Pod-Coverage-1.06
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Test-Pod-Coverage/
COMMENT=		Check for pod coverage in your distribution

DEPENDS+=		p5-Pod-Coverage-[0-9]*:../../textproc/p5-Pod-Coverage

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Test/Pod/Coverage/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
