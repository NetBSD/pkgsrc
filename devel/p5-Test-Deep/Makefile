# $NetBSD: Makefile,v 1.24 2015/08/06 02:01:34 wen Exp $

DISTNAME=		Test-Deep-0.117
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		rhaen@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Test-Deep/
COMMENT=		Perl5 module to test deep structures
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-Test-Simple>=1.001010:../../devel/p5-Test-Simple
DEPENDS+=		p5-Test-NoWarnings>=0.02:../../devel/p5-Test-NoWarnings

PERL5_PACKLIST=		auto/Test/Deep/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
