# $NetBSD: Makefile,v 1.17 2017/06/05 14:22:23 ryoon Exp $

DISTNAME=		App-Sqitch-0.9995
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		databases perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=App/}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://sqitch.org/
COMMENT=		Sane database change management
LICENSE=		mit

DEPENDS+=		p5-Class-XSAccessor>=1.18:../../devel/p5-Class-XSAccessor
DEPENDS+=		p5-Clone-[0-9]*:../../devel/p5-Clone
DEPENDS+=		p5-Config-GitLike>=1.11:../../devel/p5-Config-GitLike
DEPENDS+=		p5-DBI-[0-9]*:../../databases/p5-DBI
DEPENDS+=		p5-DateTime-[0-9]*:../../time/p5-DateTime
DEPENDS+=		p5-Devel-StackTrace>=1.30:../../devel/p5-Devel-StackTrace
DEPENDS+=		p5-Digest-SHA-[0-9]*:../../security/p5-Digest-SHA
#DEPENDS+=		{perl>=5.7.3,p5-Encode-[0-9]*}:../../textproc/p5-Encode
DEPENDS+=		p5-File-HomeDir-[0-9]*:../../devel/p5-File-HomeDir
#DEPENDS+=		{perl>=5.001,p5-File-Path-[0-9]*}:../../devel/p5-File-Path
#DEPENDS+=		{perl>=5.6.1,p5-File-Temp-[0-9]*}:../../devel/p5-File-Temp
#DEPENDS+=		{perl>=5,p5-Getopt-Long-[0-9]*}:../../devel/p5-Getopt-Long
DEPENDS+=		p5-Hash-Merge-[0-9]*:../../devel/p5-Hash-Merge
DEPENDS+=		p5-IO-Pager-[0-9]*:../../devel/p5-IO-Pager
DEPENDS+=		p5-IPC-System-Simple>=1.17:../../devel/p5-IPC-System-Simple
DEPENDS+=		p5-List-MoreUtils-[0-9]*:../../devel/p5-List-MoreUtils
DEPENDS+=		p5-Locale-libintl-[0-9]*:../../misc/p5-Locale-libintl
DEPENDS+=		p5-Moo>=1.002000:../../devel/p5-Moo
DEPENDS+=		p5-Path-Class-[0-9]*:../../devel/p5-Path-Class
DEPENDS+=		p5-PerlIO-utf8_strict-[0-9]*:../../devel/p5-PerlIO-utf8_strict
DEPENDS+=		p5-Scalar-List-Utils-[0-9]*:../../devel/p5-Scalar-List-Utils
DEPENDS+=		p5-String-Formatter-[0-9]*:../../textproc/p5-String-Formatter
DEPENDS+=		p5-String-ShellQuote-[0-9]*:../../textproc/p5-String-ShellQuote
DEPENDS+=		p5-Sub-Exporter-[0-9]*:../../devel/p5-Sub-Exporter
DEPENDS+=		p5-Template-Tiny>=0.11:../../textproc/p5-Template-Tiny
DEPENDS+=		p5-Term-ANSIColor>=2.02:../../devel/p5-Term-ANSIColor
DEPENDS+=		p5-Throwable>=0.200009:../../devel/p5-Throwable
DEPENDS+=		p5-Try-Tiny-[0-9]*:../../devel/p5-Try-Tiny
DEPENDS+=		p5-Type-Tiny-[0-9]*:../../devel/p5-Type-Tiny
DEPENDS+=		p5-Type-Tiny-XS>=0.010:../../devel/p5-Type-Tiny-XS
DEPENDS+=		p5-URI-[0-9]*:../../www/p5-URI
DEPENDS+=		p5-URI-db>=0.15:../../www/p5-URI-db
DEPENDS+=		p5-namespace-autoclean>=0.16:../../devel/p5-namespace-autoclean
#DEPENDS+=		{perl>=5.10.1,p5-parent-[0-9]*}:../../devel/p5-parent
#DEPENDS+=		{perl>=5.9.3,p5-Pod-Simple>=1.41}:../../textproc/p5-Pod-Simple

# XXX TEST_TARGET
BUILD_DEPENDS+=		p5-Capture-Tiny>=0.12:../../devel/p5-Capture-Tiny
BUILD_DEPENDS+=		p5-DBD-SQLite-[0-9]*:../../databases/p5-DBD-SQLite
BUILD_DEPENDS+=		p5-Test-Deep-[0-9]*:../../devel/p5-Test-Deep
BUILD_DEPENDS+=		p5-Test-Dir-[0-9]*:../../devel/p5-Test-Dir
BUILD_DEPENDS+=		p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception
BUILD_DEPENDS+=		p5-Test-File-[0-9]*:../../devel/p5-Test-File
BUILD_DEPENDS+=		p5-Test-File-Contents>=0.05:../../devel/p5-Test-File-Contents
BUILD_DEPENDS+=		p5-Test-MockModule>=0.05:../../devel/p5-Test-MockModule
BUILD_DEPENDS+=		p5-Test-NoWarnings>=0.083:../../devel/p5-Test-NoWarnings

USE_LANGUAGES=		# empty
USE_TOOLS+=		perl
PERL5_PACKLIST=		auto/App/Sqitch/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
