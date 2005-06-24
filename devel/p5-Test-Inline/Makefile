# $NetBSD: Makefile,v 1.9 2005/06/24 20:31:04 wiz Exp $

DISTNAME=		Test-Inline-2.002
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5tin
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Test-Inline/
COMMENT=		Inlining your tests next to the code being tested

BUILD_DEPENDS+=		p5-ExtUtils-AutoInstall>=0.49:../../devel/p5-ExtUtils-AutoInstall
DEPENDS+=		p5-Algorithm-Dependency>=1.02:../../devel/p5-Algorithm-Dependency
DEPENDS+=		p5-Class-Autouse>=1.15:../../devel/p5-Class-Autouse
DEPENDS+=		p5-File-Find-Rule>=0.26:../../devel/p5-File-Find-Rule
DEPENDS+=		p5-File-Flat>=0.95:../../devel/p5-File-Flat
DEPENDS+=		p5-File-Slurp>=9999.04:../../devel/p5-File-Slurp
DEPENDS+=		p5-Test-Simple>=0.33:../../devel/p5-Test-Simple

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Test/Inline/.packlist

.include "../../devel/p5-Test-Harness/depends.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
