# $NetBSD: Makefile,v 1.1.1.1 2004/10/31 14:40:06 seb Exp $

DISTNAME=		Test-Builder-Tester-1.01
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5tbt
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		seb@NetBSD.org
COMMENT=		Perl5 module to test testsuites built with Test::Builder

USE_BUILDLINK3=		yes
USE_LANGUAGES=		# empty
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Test/Builder/Tester/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
