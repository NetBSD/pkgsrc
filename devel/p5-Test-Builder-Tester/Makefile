# $NetBSD: Makefile,v 1.2 2004/12/20 11:31:03 grant Exp $

DISTNAME=		Test-Builder-Tester-1.01
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5tbt
PKGREVISION=		1
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		seb@NetBSD.org
COMMENT=		Perl5 module to test testsuites built with Test::Builder

USE_BUILDLINK3=		yes
USE_LANGUAGES=		# empty
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Test/Builder/Tester/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
