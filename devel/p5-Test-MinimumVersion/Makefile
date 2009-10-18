# $NetBSD: Makefile,v 1.1.1.1 2009/10/18 11:24:24 sno Exp $
#

DISTNAME=		Test-MinimumVersion-0.011
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Test-MinimumVersion/
COMMENT=		Test to prove a module requires newer perl than expected
LICENSE=		${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		p5-File-Find-Rule-Perl-[0-9]*:../../devel/p5-File-Find-Rule-Perl
DEPENDS+=		p5-Perl-MinimumVersion>=1.2:../../devel/p5-Perl-MinimumVersion

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Test/MinimumVersion/.packlist
#PERL5_MODULE_TYPE=	Module::Install::Bundled
MAKE_PARAMS=		--skipdeps

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
