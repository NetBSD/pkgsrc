# $NetBSD: Makefile,v 1.3 2004/12/20 11:30:58 grant Exp $
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

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Class/WhiteHole/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
