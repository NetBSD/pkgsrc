# $NetBSD: Makefile,v 1.2 2005/04/11 21:45:35 tv Exp $
#

DISTNAME=		Test-Taint-1.04
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Test-Taint/
COMMENT=		Tools to test taintedness

#DEPENDS+=		p5-Array-Compare-[0-9]*:../../devel/p5-Array-Compare

USE_LANGUAGES=		c
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Test/Taint/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
