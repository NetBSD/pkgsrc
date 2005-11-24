# $NetBSD: Makefile,v 1.15 2005/11/24 18:52:20 wiz Exp $
#

DISTNAME=		Class-ReturnValue-0.53
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5clv
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
