# $NetBSD: Makefile,v 1.2 2004/11/12 17:36:40 seb Exp $
#

DISTNAME=		Class-WhiteHole-0.04
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5cwh
CATEGORIES=		perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Class-WhiteHole/
COMMENT=		Perl5 module to ensure error on unhandled method calls

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Class/WhiteHole/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
