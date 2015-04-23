# $NetBSD: Makefile,v 1.22 2015/04/23 06:56:32 mef Exp $

DISTNAME=		Test-Deep-0.115
PKGNAME=		p5-${DISTNAME}
PKGREVSION=		1
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
