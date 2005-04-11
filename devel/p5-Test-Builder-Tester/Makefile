# $NetBSD: Makefile,v 1.4 2005/04/11 21:45:35 tv Exp $

DISTNAME=		Test-Builder-Tester-1.01
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5tbt
PKGREVISION=		1
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		seb@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Test-Builder-Tester/
COMMENT=		Perl5 module to test testsuites built with Test::Builder

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Test/Builder/Tester/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
