# $NetBSD: Makefile,v 1.24 2022/06/28 11:33:26 wiz Exp $

DISTNAME=		Test-MinimumVersion-0.101082
PKGNAME=		p5-${DISTNAME:C/([0-9][0-9][0-9])([0-9][0-9][0-9])/\1.\2/}
PKGREVISION=		7
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Test-MinimumVersion
COMMENT=		Test to prove a module requires newer perl than expected
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-File-Find-Rule-[0-9]*:../../devel/p5-File-Find-Rule
DEPENDS+=		p5-File-Find-Rule-Perl-[0-9]*:../../devel/p5-File-Find-Rule-Perl
DEPENDS+=		p5-Perl-MinimumVersion>=1.20:../../devel/p5-Perl-MinimumVersion
DEPENDS+=		p5-YAML-Tiny>=1.40:../../textproc/p5-YAML-Tiny
#DEPENDS+=		{perl>=5.10.0,p5-version>=0.7000}:../../devel/p5-version

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Test/MinimumVersion/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
