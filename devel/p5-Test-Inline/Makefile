# $NetBSD: Makefile,v 1.8 2005/04/11 21:45:35 tv Exp $

DISTNAME=		Test-Inline-0.15
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5tin
PKGREVISION=		1
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Inlining your tests next to the code being tested

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Test/Inline/.packlist

DEPENDS+=		p5-Test-Simple>=0.33:../../devel/p5-Test-Simple

.include "../../devel/p5-Test-Harness/depends.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
