# $NetBSD: Makefile,v 1.6 2010/03/09 21:56:59 sno Exp $
#

DISTNAME=	Padre-0.58
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	editors perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Padre/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Padre/
COMMENT=	Perl Application Development and Refactoring Environment
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_JOBS_SAFE=		no

USE_LANGUAGES+=	c c++
REPLACE_PERL+=	share/templates/*.t
REPLACE_PERL+=	share/templates/*.pl
REPLACE_PERL+=	share/examples/wx/*.pl
REPLACE_PERL+=	share/examples/absolute_beginner/*.pl

BUILD_DEPENDS+=	p5-Capture-Tiny>=0.06:../../devel/p5-Capture-Tiny
BUILD_DEPENDS+=	p5-Locale-Msgfmt>=0.14:../../devel/p5-Locale-Msgfmt
BUILD_DEPENDS+=	p5-Test-Exception>=0.27:../../devel/p5-Test-Exception
BUILD_DEPENDS+=	{perl>=5.10.1,p5-Test-Simple>=0.88}:../../devel/p5-Test-Simple
BUILD_DEPENDS+=	p5-Test-NoWarnings>=0.084:../../devel/p5-Test-NoWarnings
BUILD_DEPENDS+= p5-Test-Script>=1.07:../../devel/p5-Test-Script

DEPENDS+=	p5-ack>=1.86:../../textproc/p5-ack
DEPENDS+=	p5-Class-Adapter>=1.05:../../devel/p5-Class-Adapter
DEPENDS+=	p5-Class-Unload>=0.03:../../devel/p5-Class-Unload
DEPENDS+=	p5-Class-XSAccessor>=1.05:../../devel/p5-Class-XSAccessor
# Cwd 0.2701 is in Perl 5.8.9, but Perl 5.10.0 contains "only" 3.2501
DEPENDS+=	{perl>=5.10.1,p5-PathTools>=3.27.01}:../../devel/p5-PathTools
DEPENDS+=	p5-DBD-SQLite>=1.27:../../databases/p5-DBD-SQLite
DEPENDS+=	p5-Debug-Client>=0.11:../../devel/p5-Debug-Client
DEPENDS+=	p5-Devel-Dumpvar>=0.04:../../devel/p5-Devel-Dumpvar
DEPENDS+=	p5-Devel-Refactor>=0.05:../../devel/p5-Devel-Refactor
# Encode 2.26 is in Perl 5.8.9, but Perl 5.10.0 contains "only" 2.23
DEPENDS+=	{perl>=5.10.1,p5-Encode>=2.26}:../../textproc/p5-Encode
DEPENDS+=	p5-ExtUtils-MakeMaker>=6.56:../../devel/p5-ExtUtils-MakeMaker
DEPENDS+=       {perl>=5.10.1,p5-ExtUtils-Manifest>=1.56}:../../devel/p5-ExtUtils-Manifest
DEPENDS+=       p5-File-Copy-Recursive>=0.37:../../sysutils/p5-File-Copy-Recursive
DEPENDS+=	p5-File-Find-Rule>=0.30:../../devel/p5-File-Find-Rule
DEPENDS+=	p5-File-HomeDir>=0.84:../../devel/p5-File-HomeDir
DEPENDS+=	p5-File-Next>=1.06:../../devel/p5-File-Next
# File::Path 2.07 is in Perl 5.8.9, but Perl 5.10.0 contains "only" 2.04
DEPENDS+=	{perl>=5.10.1,p5-File-Path>=2.07}:../../devel/p5-File-Path
DEPENDS+=	p5-File-Remove>=1.42:../../sysutils/p5-File-Remove
DEPENDS+=	p5-File-ShareDir>=1.00:../../devel/p5-File-ShareDir
DEPENDS+=	p5-File-Which>=1.08:../../devel/p5-File-Which
DEPENDS+=	p5-Format-Human-Bytes>=0.04:../../devel/p5-Format-Human-Bytes
DEPENDS+=	p5-HTML-Parser>=3.58:../../www/p5-HTML-Parser
DEPENDS+=	p5-IO-stringy>=2.110:../../devel/p5-IO-stringy
DEPENDS+=	p5-IO-String>=1.08:../../devel/p5-IO-String
DEPENDS+=	p5-List-MoreUtils>=0.22:../../devel/p5-List-MoreUtils
DEPENDS+=	{perl>=5.8.8,p5-Scalar-List-Utils>=1.18}:../../devel/p5-Scalar-List-Utils
DEPENDS+=	{perl>=5.8.9,p5-Module-CoreList-[0-9]*}:../../devel/p5-Module-CoreList
DEPENDS+=	p5-Module-Refresh>=0.13:../../devel/p5-Module-Refresh
DEPENDS+=	p5-Module-Starter>=1.500:../../devel/p5-Module-Starter
DEPENDS+=	p5-ORLite>=1.38:../../databases/p5-ORLite
DEPENDS+=	p5-PPI>=1.205:../../devel/p5-PPI
DEPENDS+=	p5-PPIx-EditorTools>=0.09:../../editors/p5-PPIx-EditorTools
DEPENDS+=	p5-Params-Util>=0.33:../../devel/p5-Params-Util
DEPENDS+=	p5-Parse-ErrorString-Perl>=0.11:../../devel/p5-Parse-ErrorString-Perl
DEPENDS+=	p5-Parse-ExuberantCTags>=1.00:../../devel/p5-Parse-ExuberantCTags
DEPENDS+=	p5-Pod-Abstract>=0.16:../../textproc/p5-Pod-Abstract
DEPENDS+=	p5-Pod-POM>=0.17:../../textproc/p5-Pod-POM
DEPENDS+=	{perl>=5.10.1,p5-Pod-Simple>=3.07}:../../textproc/p5-Pod-Simple
DEPENDS+=	p5-Probe-Perl>=0.01:../../devel/p5-Probe-Perl
DEPENDS+=	{perl>=5.8.8,p5-Storable>=2.15}:../../devel/p5-Storable
DEPENDS+=	p5-Readonly-XS>=1.05:../../devel/p5-Readonly-XS
DEPENDS+=	p5-Template-Tiny>=0.03:../../textproc/p5-Template-Tiny
DEPENDS+=	{perl>=5.11.0,p5-Text-Balanced>=2.01}:../../textproc/p5-Text-Balanced
DEPENDS+=	p5-Text-Diff>=0.35:../../textproc/p5-Text-Diff
DEPENDS+=	p5-Text-FindIndent>=0.06:../../textproc/p5-Text-FindIndent
# Thread::Queue 2.11 is in Perl 5.8.9, but Perl 5.10.0 contains "only" 2.00
#DEPENDS+=	{perl>=5.10.1,p5-Thread-Queue>=2.11}:../../devel/p5-Thread-Queue # XXX missing
PERL5_REQD+=	5.10.1
DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI
DEPENDS+=	p5-Wx-Perl-ProcessStream>=0.25:../../x11/p5-Wx-Perl-ProcessStream
DEPENDS+=	p5-YAML-Tiny>=1.32:../../textproc/p5-YAML-Tiny
DEPENDS+=	p5-pip>=0.13:../../devel/p5-pip
DEPENDS+=	p5-version>=0.8000:../../devel/p5-version
# threads, threads::shared and version are in 5.10.1 core - we don't need to note again the 5.10.1 req

PERL5_PACKLIST=		auto/Padre/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

#pre-configure:
#	cd ${WRKSRC} && find `pwd` -name "*.orig" -type f | xargs rm

.include "../../lang/perl5/module.mk"
.include "../../databases/p5-DBI/buildlink3.mk"
BUILDLINK_API_DEPENDS.p5-DBI+=  p5-DBI>=1.580
.include "../../x11/p5-Wx/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
