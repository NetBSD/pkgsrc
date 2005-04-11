# $NetBSD: Makefile,v 1.2 2005/04/11 21:45:35 tv Exp $
#

DISTNAME=		Sub-Uplevel-0.09
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Sub/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Sub-Uplevel/
COMMENT=		Apparently run a function in a higher stack frame

#DEPENDS+=		p5-Devel-Cycle-[0-9]*:../../devel/p5-Devel-Cycle

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Sub/Uplevel/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
