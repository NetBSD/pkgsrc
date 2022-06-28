# $NetBSD: Makefile,v 1.21 2022/06/28 11:33:22 wiz Exp $

DISTNAME=		Test-CleanNamespaces-0.24
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		4
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		wen@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Test-CleanNamespaces
COMMENT=		Check for uncleaned imports
LICENSE=		${PERL5_LICENSE}

DEPENDS+=	p5-namespace-clean>=0:../../devel/p5-namespace-clean
DEPENDS+=	p5-Role-Tiny>=0:../../devel/p5-Role-Tiny
DEPENDS+=	p5-Package-Stash-XS>=0:../../devel/p5-Package-Stash-XS

TEST_DEPENDS+=	p5-Test-Warnings>=0:../../devel/p5-Test-Warnings
TEST_DEPENDS+=	p5-Test-Requires-[0-9]*:../../devel/p5-Test-Requires
TEST_DEPENDS+=	p5-Test-Deep-[0-9]*:../../devel/p5-Test-Deep
TEST_DEPENDS+=	p5-Sub-Identify-[0-9]*:../../devel/p5-Sub-Identify
TEST_DEPENDS+=	p5-namespace-clean>=0:../../devel/p5-namespace-clean
TEST_DEPENDS+=	p5-Test-Needs>=0:../../devel/p5-Test-Needs
TEST_DEPENDS+=	p5-File-pushd>=0:../../devel/p5-File-pushd

PERL5_PACKLIST=		auto/Test/CleanNamespaces/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
