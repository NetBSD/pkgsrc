# $NetBSD: Makefile,v 1.2 2010/01/25 14:11:03 sno Exp $
#

DISTNAME=		Test-MinimumVersion-0.013
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
DEPENDS+=		p5-Test-Tester-[0-9]*:../../devel/p5-Test-Tester
DEPENDS+=		p5-YAML-Tiny>=1.40:../../textproc/p5-YAML-Tiny
DEPENDS+=		{perl>=5.10.0,p5-version>=0.7000}:../../devel/p5-version

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Test/MinimumVersion/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
