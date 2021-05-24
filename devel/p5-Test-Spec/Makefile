# $NetBSD: Makefile,v 1.20 2021/05/24 19:51:49 wiz Exp $

DISTNAME=		Test-Spec-0.54
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		4
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Test-Spec
COMMENT=		Perl5 module for writing tests in a declarative specification style
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-Package-Stash>=0.23:../../devel/p5-Package-Stash
DEPENDS+=		p5-Test-Deep>=0.103:../../devel/p5-Test-Deep
DEPENDS+=		p5-Test-Trap-[0-9]*:../../devel/p5-Test-Trap
DEPENDS+=		p5-Tie-IxHash-[0-9]*:../../devel/p5-Tie-IxHash

PERL5_PACKLIST=		auto/Test/Spec/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
