# $NetBSD: Makefile,v 1.3 2006/10/28 08:50:59 obache Exp $

DISTNAME=		Test-Deep-0.096
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Test-Deep/
COMMENT=		Perl5 module to test deep structures

DEPENDS+=		p5-Test-Tester>=0.04:../../devel/p5-Test-Tester
DEPENDS+=		p5-Test-NoWarnings>=0.02:../../devel/p5-Test-NoWarnings

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Test/Deep/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
