# $NetBSD: Makefile,v 1.8 2015/02/03 01:02:27 mef Exp $

DISTNAME=		Test-Spec-0.49
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Test-Spec/
COMMENT=		Perl5 module for writing tests in a declarative specification style
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-Package-Stash>=0.23:../../devel/p5-Package-Stash
DEPENDS+=		p5-Test-Deep>=0.103:../../devel/p5-Test-Deep
DEPENDS+=		p5-Test-Trap-[0-9]*:../../devel/p5-Test-Trap
DEPENDS+=		p5-Tie-IxHash-[0-9]*:../../devel/p5-Tie-IxHash

PERL5_PACKLIST=		auto/Test/Spec/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
