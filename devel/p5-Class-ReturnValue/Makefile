# $NetBSD: Makefile,v 1.13 2005/07/19 10:20:07 grant Exp $
#

DISTNAME=		Class-ReturnValue-0.52
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5clv
PKGREVISION=		1
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Class-ReturnValue/
COMMENT=		Perl5 module for return-value object

PERL5_PACKLIST=		auto/Class/ReturnValue/.packlist

DEPENDS+=		p5-Devel-StackTrace-[0-9]*:../../devel/p5-Devel-StackTrace
DEPENDS+=		p5-Test-Inline-[0-9]*:../../devel/p5-Test-Inline

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
