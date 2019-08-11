# $NetBSD: Makefile,v 1.27 2019/08/11 13:19:49 wiz Exp $

DISTNAME=		Module-CPANTS-Analyse-1.00
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Module-CPANTS-Analyse
COMMENT=		Perl5 module to generate Kwalitee ratings for a distribution
LICENSE=		${PERL5_LICENSE}

DEPENDS+=	p5-Archive-Any-Lite>=0.06:../../archivers/p5-Archive-Any-Lite
#DEPENDS+=	{perl>=5.10,p5-Archive-Tar>=1.30}:../../archivers/p5-Archive-Tar
DEPENDS+=	p5-Array-Diff>=0.04:../../devel/p5-Array-Diff
DEPENDS+=	p5-CPAN-DistnameInfo>=0.06:../../devel/p5-CPAN-DistnameInfo
#DEPENDS+=	{perl>=5.19.1,p5-CPAN-Meta>=2.131490}:../../devel/p5-CPAN-Meta
DEPENDS+=	p5-Class-Accessor>=0.19:../../devel/p5-Class-Accessor
DEPENDS+=	p5-Data-Binary>=0:../../devel/p5-Data-Binary
DEPENDS+=	p5-ExtUtils-MakeMaker-CPANfile-[0-9]*:../../devel/p5-ExtUtils-MakeMaker-CPANfile
DEPENDS+=	p5-File-Find-Rule-VCS>=0:../../devel/p5-File-Find-Rule-VCS
DEPENDS+=	p5-IO-Capture>=0.05:../../devel/p5-IO-Capture
DEPENDS+=	p5-List-MoreUtils>=0:../../devel/p5-List-MoreUtils
DEPENDS+=	p5-Module-ExtractUse>=0.30:../../devel/p5-Module-ExtractUse
DEPENDS+=	p5-Module-Find>=0:../../devel/p5-Module-Find
DEPENDS+=	p5-Module-Pluggable>=2.96:../../devel/p5-Module-Pluggable
DEPENDS+=	p5-Perl-PrereqScanner-NotQuiteLite>=0.9901:../../devel/p5-Perl-PrereqScanner-NotQuiteLite
#DEPENDS+=	{perl>=5.10,p5-Pod-Simple>=2.02}:../../textproc/p5-Pod-Simple
DEPENDS+=	p5-Readonly>=0:../../devel/p5-Readonly
DEPENDS+=	p5-Set-Scalar>=0:../../devel/p5-Set-Scalar
DEPENDS+=	p5-Software-License>=0.003:../../devel/p5-Software-License
DEPENDS+=	p5-Test-YAML-Meta>=0.11:../../devel/p5-Test-YAML-Meta
DEPENDS+=	p5-YAML-Syck>=0.95:../../textproc/p5-YAML-Syck
DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww
#DEPENDS+=	{perl>=5.10,p5-version>=0.73}:../../devel/p5-version

BUILD_DEPENDS+=	p5-Test-Deep-[0-9]*:../../devel/p5-Test-Deep
BUILD_DEPENDS+=	p5-Test-NoWarnings-[0-9]*:../../devel/p5-Test-NoWarnings
BUILD_DEPENDS+=	p5-Test-Warn>=0.11:../../devel/p5-Test-Warn
BUILD_DEPENDS+=	p5-Test-FailWarnings-[0-9]*:../../devel/p5-Test-FailWarnings
BUILD_DEPENDS+=	p5-Archive-Zip-[0-9]*:../../archivers/p5-Archive-Zip
BUILD_DEPENDS+=	p5-File-Find-Object-[0-9]*:../../devel/p5-File-Find-Object
BUILD_DEPENDS+=	p5-Class-XSAccessor-[0-9]*:../../devel/p5-Class-XSAccessor
BUILD_DEPENDS+=	p5-JSON-MaybeXS-[0-9]*:../../converters/p5-JSON-MaybeXS

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Module/CPANTS/Analyse/.packlist
#ERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
