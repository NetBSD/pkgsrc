# $NetBSD: Makefile,v 1.2 2005/04/11 21:45:35 tv Exp $
#

DISTNAME=		Test-Exception-0.20
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Test-Exception/
COMMENT=		Test exception based code

DEPENDS+=		p5-Sub-Uplevel-[0-9]*:../../devel/p5-Sub-Uplevel

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Test/Exception/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
