# $NetBSD: Makefile,v 1.3 2013/11/24 10:02:40 wiz Exp $

DISTNAME=		App-Sqitch-0.961
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
CATEGORIES=		databases perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=App/}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://sqitch.org/
COMMENT=		Sane database change management
LICENSE=		mit

DEPENDS+=		p5-Config-GitLike>=1.09:../../devel/p5-Config-GitLike
DEPENDS+=		p5-DBI-[0-9]*:../../databases/p5-DBI
DEPENDS+=		p5-DateTime-[0-9]*:../../time/p5-DateTime
DEPENDS+=		p5-Digest-SHA1-[0-9]*:../../security/p5-Digest-SHA1
DEPENDS+=		p5-Encode-[0-9]*:../../textproc/p5-Encode
DEPENDS+=		p5-File-HomeDir-[0-9]*:../../devel/p5-File-HomeDir
DEPENDS+=		p5-File-Path-[0-9]*:../../devel/p5-File-Path
DEPENDS+=		p5-File-Temp-[0-9]*:../../devel/p5-File-Temp
#DEPENDS+=		p5-Getopt-Long-[0-9]*:../../devel/p5-Getopt-Long
DEPENDS+=		p5-Git-Wrapper-[0-9]*:../../devel/p5-Git-Wrapper
DEPENDS+=		p5-Hash-Merge-[0-9]*:../../devel/p5-Hash-Merge
DEPENDS+=		p5-IO-Pager-[0-9]*:../../devel/p5-IO-Pager
DEPENDS+=		p5-IPC-System-Simple>=1.17:../../devel/p5-IPC-System-Simple
DEPENDS+=		p5-List-MoreUtils-[0-9]*:../../devel/p5-List-MoreUtils
DEPENDS+=		p5-Moose-[0-9]*:../../devel/p5-Moose
DEPENDS+=		p5-Mouse>=1.04:../../devel/p5-Mouse
DEPENDS+=		p5-MouseX-NativeTraits-[0-9]*:../../devel/p5-MouseX-NativeTraits
DEPENDS+=		p5-MouseX-Types-Path-Class-[0-9]*:../../devel/p5-MouseX-Types-Path-Class
DEPENDS+=		p5-Path-Class-[0-9]*:../../devel/p5-Path-Class
DEPENDS+=		p5-Role-HasMessage>=0.005:../../devel/p5-Role-HasMessage
DEPENDS+=		p5-Role-Identifiable-[0-9]*:../../devel/p5-Role-Identifiable
DEPENDS+=		p5-String-Formatter-[0-9]*:../../textproc/p5-String-Formatter
DEPENDS+=		p5-Sub-Exporter-[0-9]*:../../devel/p5-Sub-Exporter
DEPENDS+=		p5-Template-Tiny>=0.11:../../textproc/p5-Template-Tiny
#DEPENDS+=		p5-Term-ANSIColor>=2.02:../../devel/p5-Term-ANSIColor
DEPENDS+=		p5-Throwable-[0-9]*:../../devel/p5-Throwable
DEPENDS+=		p5-Try-Tiny-[0-9]*:../../devel/p5-Try-Tiny
DEPENDS+=		p5-URI-[0-9]*:../../www/p5-URI
DEPENDS+=		p5-constant-[0-9]*:../../devel/p5-constant
DEPENDS+=		p5-namespace-autoclean>=0.11:../../devel/p5-namespace-autoclean
DEPENDS+=		p5-parent-[0-9]*:../../devel/p5-parent
DEPENDS+=		p5-Devel-StackTrace>=1.30:../../devel/p5-Devel-StackTrace
DEPENDS+=		p5-Pod-Simple>=1.41:../../textproc/p5-Pod-Simple

# XXX TEST_TARGET
BUILD_DEPENDS+=		p5-Capture-Tiny>=0.12:../../devel/p5-Capture-Tiny
BUILD_DEPENDS+=		p5-DBD-SQLite-[0-9]*:../../databases/p5-DBD-SQLite
BUILD_DEPENDS+=		p5-Test-Deep-[0-9]*:../../devel/p5-Test-Deep
BUILD_DEPENDS+=		p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception
BUILD_DEPENDS+=		p5-Test-File-Contents>=0.05:../../devel/p5-Test-File-Contents
BUILD_DEPENDS+=		p5-Test-MockModule>=0.05:../../devel/p5-Test-MockModule
BUILD_DEPENDS+=		p5-Test-NoWarnings>=0.083:../../devel/p5-Test-NoWarnings

USE_LANGUAGES=		# empty
USE_TOOLS+=		perl
PERL5_PACKLIST=		auto/App/Sqitch/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
