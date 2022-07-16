# $NetBSD: Makefile,v 1.41 2022/07/16 07:23:15 wen Exp $

DISTNAME=	Dist-Zilla-6.025
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Dist/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Dist-Zilla
COMMENT=	Perl 5 module distribution builder; installer not included
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-App-Cmd>=0.330:../../devel/p5-App-Cmd
DEPENDS+=	p5-Archive-Tar-Wrapper-[0-9]*:../../archivers/p5-Archive-Tar-Wrapper
#DEPENDS+=	{perl>=5.16.0,p5-CPAN-Meta>=2.120630}:../../devel/p5-CPAN-Meta
#DEPENDS+=	{perl>=5.18.0,p5-CPAN-Meta-Requirements>=2.121}:../../devel/p5-CPAN-Meta-Requirements
DEPENDS+=	p5-CPAN-Uploader>=0.103004:../../devel/p5-CPAN-Uploader
DEPENDS+=	p5-Class-Load>=0.17:../../devel/p5-Class-Load
DEPENDS+=	p5-Config-INI-[0-9]*:../../devel/p5-Config-INI
DEPENDS+=	p5-Config-MVP>=2.200011:../../devel/p5-Config-MVP
DEPENDS+=	p5-Config-MVP-Reader-INI>=2.101461:../../devel/p5-Config-MVP-Reader-INI
DEPENDS+=	p5-Data-Section>=0.200.002:../../devel/p5-Data-Section
DEPENDS+=	p5-DateTime>=0.4400:../../time/p5-DateTime
DEPENDS+=	p5-File-Copy-Recursive>=0.41:../../sysutils/p5-File-Copy-Recursive
DEPENDS+=	p5-File-Find-Rule-[0-9]*:../../devel/p5-File-Find-Rule
DEPENDS+=	p5-File-HomeDir-[0-9]*:../../devel/p5-File-HomeDir
DEPENDS+=	p5-File-ShareDir-[0-9]*:../../devel/p5-File-ShareDir
DEPENDS+=	p5-File-ShareDir-Install>=0.06:../../devel/p5-File-ShareDir-Install
DEPENDS+=	p5-File-pushd-[0-9]*:../../devel/p5-File-pushd
DEPENDS+=	p5-Hash-Merge-Simple-[0-9]*:../../devel/p5-Hash-Merge-Simple
DEPENDS+=	p5-JSON>=2.00:../../converters/p5-JSON
DEPENDS+=	p5-JSON-MaybeXS-[0-9]*:../../converters/p5-JSON-MaybeXS
DEPENDS+=	p5-List-AllUtils-[0-9]*:../../devel/p5-List-AllUtils
DEPENDS+=	p5-List-MoreUtils-[0-9]*:../../devel/p5-List-MoreUtils
DEPENDS+=	p5-Log-Dispatchouli>=1.102.220:../../devel/p5-Log-Dispatchouli
DEPENDS+=	p5-Moose>=0.9200:../../devel/p5-Moose
DEPENDS+=	p5-Moose-Autobox>=0.10:../../devel/p5-Moose-Autobox
DEPENDS+=	p5-MooseX-LazyRequire-[0-9]*:../../devel/p5-MooseX-LazyRequire
DEPENDS+=	p5-MooseX-Role-Parameterized-[0-9]*:../../devel/p5-MooseX-Role-Parameterized
DEPENDS+=	p5-MooseX-SetOnce-[0-9]*:../../devel/p5-MooseX-SetOnce
DEPENDS+=	p5-MooseX-Types-[0-9]*:../../devel/p5-MooseX-Types
DEPENDS+=	p5-MooseX-Types-Path-Class-[0-9]*:../../devel/p5-MooseX-Types-Path-Class
DEPENDS+=	p5-MooseX-Types-Perl-[0-9]*:../../devel/p5-MooseX-Types-Perl
DEPENDS+=	p5-PPI>=1.222:../../devel/p5-PPI
DEPENDS+=	p5-Params-Util-[0-9]*:../../devel/p5-Params-Util
DEPENDS+=	p5-Path-Class-[0-9]*:../../devel/p5-Path-Class
DEPENDS+=	p5-Perl-PrereqScanner>=1.016:../../devel/p5-Perl-PrereqScanner
DEPENDS+=	p5-Perl-Version-[0-9]*:../../devel/p5-Perl-Version
DEPENDS+=	p5-Pod-Eventual>=0.091.480:../../textproc/p5-Pod-Eventual
DEPENDS+=	p5-Software-License>=0.104.001:../../devel/p5-Software-License
DEPENDS+=	p5-String-Formatter>=0.100680:../../textproc/p5-String-Formatter
DEPENDS+=	p5-String-RewritePrefix>=0.005:../../textproc/p5-String-RewritePrefix
DEPENDS+=	p5-Sub-Exporter-ForMethods-[0-9]*:../../devel/p5-Sub-Exporter-ForMethods
DEPENDS+=	p5-Term-Encoding>=0:../../devel/p5-Term-Encoding
DEPENDS+=	p5-Term-ReadKey-[0-9]*:../../devel/p5-Term-ReadKey
DEPENDS+=	p5-Term-UI-[0-9]*:../../devel/p5-Term-UI
# Term::ReadLine is part of core
DEPENDS+=	p5-Test-Deep-[0-9]*:../../devel/p5-Test-Deep
DEPENDS+=	p5-Text-Glob>=0.08:../../textproc/p5-Text-Glob
DEPENDS+=	p5-Text-Template-[0-9]*:../../textproc/p5-Text-Template
DEPENDS+=	p5-Try-Tiny-[0-9]*:../../devel/p5-Try-Tiny
DEPENDS+=	p5-YAML-Tiny-[0-9]*:../../textproc/p5-YAML-Tiny
DEPENDS+=	p5-autobox>=2.53:../../devel/p5-autobox
DEPENDS+=	p5-namespace-autoclean-[0-9]*:../../devel/p5-namespace-autoclean

TEST_DEPENDS+=	p5-CPAN-Meta-Check>=0.011:../../devel/p5-CPAN-Meta-Check
TEST_DEPENDS+=	p5-File-ShareDir-Install>=0.03:../../devel/p5-File-ShareDir-Install
TEST_DEPENDS+=	p5-Test-Deep-[0-9]*:../../devel/p5-Test-Deep
TEST_DEPENDS+=	p5-Test-FailWarnings-[0-9]*:../../devel/p5-Test-FailWarnings
TEST_DEPENDS+=	p5-Test-Fatal-[0-9]*:../../devel/p5-Test-Fatal
TEST_DEPENDS+=	p5-Test-File-ShareDir-[0-9]*:../../devel/p5-Test-File-ShareDir

PERL5_PACKLIST=		auto/Dist/Zilla/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
