# $NetBSD: Makefile,v 1.4 2005/04/11 21:45:30 tv Exp $
#

DISTNAME=		Class-WhiteHole-0.04
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5cwh
PKGREVISION=		1
CATEGORIES=		perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Class-WhiteHole/
COMMENT=		Perl5 module to ensure error on unhandled method calls

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Class/WhiteHole/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
