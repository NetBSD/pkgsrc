# $NetBSD: Makefile,v 1.1 2013/03/15 20:59:52 schmonz Exp $
#

DISTNAME=		Test-More-Behaviour-1.0.0
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Test-More-Behaviour/
COMMENT=		BDD module for Perl modeled after Rspec
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-Term-ANSIColor>=3.00:../../devel/p5-Term-ANSIColor
DEPENDS+=		p5-version-[0-9]*:../../devel/p5-version
BUILD_DEPENDS+=		p5-IO-Capture-[0-9]*:../../devel/p5-IO-Capture

PERL5_PACKLIST=		auto/Test/More/Behaviour/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
