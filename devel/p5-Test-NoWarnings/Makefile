# $NetBSD: Makefile,v 1.1.1.1 2005/11/23 22:00:02 wiz Exp $

DISTNAME=		Test-NoWarnings-0.082
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Test-NoWarnings/
COMMENT=		Perl5 module to make sure you didn't emit any warnings while testing

DEPENDS+=		p5-Test-Tester>=0.103:../../devel/p5-Test-Tester

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Test/NoWarnings/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
