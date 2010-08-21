# $NetBSD: Makefile,v 1.9 2010/08/21 16:34:32 seb Exp $

DISTNAME=		Test-Deep-0.106
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		rhaen@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Test-Deep/
COMMENT=		Perl5 module to test deep structures
LICENSE=		${PERL5_LICENSE}

# higher Test::Tester required in case of old Test::Builder installed - so
# let's require the version detected being "compatible"
DEPENDS+=		p5-Test-Tester>=0.107:../../devel/p5-Test-Tester
DEPENDS+=		p5-Test-NoWarnings>=0.02:../../devel/p5-Test-NoWarnings

PERL5_PACKLIST=		auto/Test/Deep/.packlist
PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
