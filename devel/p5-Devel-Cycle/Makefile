# $NetBSD: Makefile,v 1.2 2005/04/11 21:45:31 tv Exp $

DISTNAME=		Devel-Cycle-1.03
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Devel-Cycle/
COMMENT=		Perl5 module to find memory cycles in objects

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Devel/Cycle/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
