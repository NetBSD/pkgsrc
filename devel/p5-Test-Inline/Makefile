# $NetBSD: Makefile,v 1.3 2003/07/17 21:32:52 grant Exp $

DISTNAME=		Test-Inline-0.15
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5tin
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Inlining your tests next to the code being tested

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Test/Inline/.packlist

DEPENDS+=		p5-Test-Simple>=0.33:../p5-Test-Simple
DEPENDS+=		p5-Test-Harness>=1.22:../p5-Test-Harness

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
