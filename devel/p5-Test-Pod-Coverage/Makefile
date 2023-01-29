# $NetBSD: Makefile,v 1.26 2023/01/29 10:16:56 wiz Exp $

DISTNAME=		Test-Pod-Coverage-1.10
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		9
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Test-Pod-Coverage
COMMENT=		Check for pod coverage in your distribution
LICENSE=		artistic-2.0

DEPENDS+=		p5-Pod-Coverage-[0-9]*:../../textproc/p5-Pod-Coverage
DEPENDS+=		p5-Pod-Parser-[0-9]*:../../textproc/p5-Pod-Parser
TEST_DEPENDS+=		p5-Test-Pod>1.14:../../devel/p5-Test-Pod

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Test/Pod/Coverage/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
