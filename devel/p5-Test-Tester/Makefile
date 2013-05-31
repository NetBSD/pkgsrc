# $NetBSD: Makefile,v 1.11 2013/05/31 12:40:51 wiz Exp $

DISTNAME=		Test-Tester-0.108
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		rhaen@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Test-Tester/
COMMENT=		Perl5 module to ease testing test modules built with Test::Builder

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Test/Tester/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
