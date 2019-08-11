# $NetBSD: Makefile,v 1.19 2019/08/11 13:20:11 wiz Exp $
#

DISTNAME=		Perl-MinimumVersion-1.38
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		5
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Perl/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Perl-MinimumVersion
COMMENT=		Find a minimum required version of perl for Perl code
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-File-Find-Rule>=0.32:../../devel/p5-File-Find-Rule
DEPENDS+=		p5-File-Find-Rule-Perl>=1.04:../../devel/p5-File-Find-Rule-Perl
#DEPENDS+=		{perl>=5.10.0,p5-Scalar-List-Utils>=1.18}:../../devel/p5-Scalar-List-Utils
DEPENDS+=		p5-PPI>=1.215:../../devel/p5-PPI
DEPENDS+=		p5-Params-Util>=0.25:../../devel/p5-Params-Util
DEPENDS+=		p5-Perl-Critic>=1.104:../../devel/p5-Perl-Critic
DEPENDS+=		p5-PPIx-Regexp>=0.033:../../devel/p5-PPIx-Regexp
#DEPENDS+=		{perl>=5.10.1,p5-version>=0.76}:../../devel/p5-version

BUILD_DEPENDS+=		p5-Test-Script>=1.03:../../devel/p5-Test-Script

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Perl/MinimumVersion/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
