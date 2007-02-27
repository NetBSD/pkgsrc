# $NetBSD: Makefile,v 1.4 2007/02/27 13:58:07 wiz Exp $

DISTNAME=		Test-LongString-0.11
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Test-LongString/
COMMENT=		Perl5 module to test strings for equality

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Test/LongString/.packlist

DEPENDS+=		p5-Test-Simple>=0.62:../../devel/p5-Test-Simple

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
