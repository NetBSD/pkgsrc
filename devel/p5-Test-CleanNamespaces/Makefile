# $NetBSD: Makefile,v 1.12 2017/06/05 14:23:41 ryoon Exp $

DISTNAME=		Test-CleanNamespaces-0.22
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		wen@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Test-CleanNamespaces/
COMMENT=		Check for uncleaned imports
LICENSE=		${PERL5_LICENSE}

DEPENDS+=	p5-namespace-clean>=0:../../devel/p5-namespace-clean
DEPENDS+=	p5-Role-Tiny>=0:../../devel/p5-Role-Tiny
DEPENDS+=	p5-Package-Stash-XS>=0:../../devel/p5-Package-Stash-XS

BUILD_DEPENDS+=	p5-Test-Warnings>=0:../../devel/p5-Test-Warnings
# for make test
BUILD_DEPENDS+=	p5-Test-Simple>=1.001010:../../devel/p5-Test-Simple
BUILD_DEPENDS+=	p5-Test-Requires-[0-9]*:../../devel/p5-Test-Requires
BUILD_DEPENDS+=	p5-Test-Deep-[0-9]*:../../devel/p5-Test-Deep
BUILD_DEPENDS+=	p5-Sub-Identify-[0-9]*:../../devel/p5-Sub-Identify
BUILD_DEPENDS+=	p5-namespace-clean>=0:../../devel/p5-namespace-clean
BUILD_DEPENDS+=	p5-Test-Needs>=0:../../devel/p5-Test-Needs
BUILD_DEPENDS+=	p5-File-pushd>=0:../../devel/p5-File-pushd

PERL5_PACKLIST=		auto/Test/CleanNamespaces/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
