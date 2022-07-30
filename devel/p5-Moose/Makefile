# $NetBSD: Makefile,v 1.125 2022/07/30 06:49:04 rillig Exp $

DISTNAME=	Moose-2.2201
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://moose.perl.org/
COMMENT=	Postmodern object system for Perl 5
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Class-Load>=0.09:../../devel/p5-Class-Load
DEPENDS+=	p5-Class-Load-XS>=0.01:../../devel/p5-Class-Load-XS
DEPENDS+=	p5-Data-OptList>=0.107:../../devel/p5-Data-OptList
DEPENDS+=	p5-Devel-GlobalDestruction>=0:../../devel/p5-Devel-GlobalDestruction
DEPENDS+=	p5-Devel-OverloadInfo>=0.005:../../devel/p5-Devel-OverloadInfo
DEPENDS+=	p5-Devel-StackTrace>=2.03:../../devel/p5-Devel-StackTrace
DEPENDS+=	p5-Dist-CheckConflicts>=0.02:../../devel/p5-Dist-CheckConflicts
DEPENDS+=	p5-Eval-Closure>=0.04:../../devel/p5-Eval-Closure #XXX
DEPENDS+=	p5-Module-Runtime>=0.014:../../devel/p5-Module-Runtime
DEPENDS+=	p5-Module-Runtime-Conflicts>=0.002:../../devel/p5-Module-Runtime-Conflicts
DEPENDS+=	p5-MRO-Compat>=0.05:../../devel/p5-MRO-Compat
DEPENDS+=	p5-Package-DeprecationManager-[0-9]*:../../devel/p5-Package-DeprecationManager
DEPENDS+=	p5-Package-Stash>=0.32:../../devel/p5-Package-Stash
DEPENDS+=	p5-Package-Stash-XS>=0.24:../../devel/p5-Package-Stash-XS
DEPENDS+=	p5-Params-Util>=1.00:../../devel/p5-Params-Util
DEPENDS+=	p5-Sub-Exporter>=0.980:../../devel/p5-Sub-Exporter
DEPENDS+=	p5-Sub-Identify>=0:../../devel/p5-Sub-Identify
DEPENDS+=	p5-Task-Weaken-[0-9]*:../../devel/p5-Task-Weaken
DEPENDS+=	p5-Try-Tiny>=0.17:../../devel/p5-Try-Tiny
DEPENDS+=	p5-namespace-autoclean-[0-9]*:../../devel/p5-namespace-autoclean
DEPENDS+=	p5-Scalar-List-Utils>=1.56:../../devel/p5-Scalar-List-Utils
# Note: Moose can take advantage of PartialDump, but as PartialDump depends
# on Moose, we cannot add it to DEPENDS

BUILD_DEPENDS+=	p5-Test-Fatal>=0.05:../../devel/p5-Test-Fatal
BUILD_DEPENDS+=	p5-Test-Requires>=0.05:../../devel/p5-Test-Requires

CONFLICTS+=	p5-Class-MOP-[0-9]*

BUILD_DEPENDS+=	p5-DBM-Deep-[0-9]*:../../databases/p5-DBM-Deep
BUILD_DEPENDS+=	p5-DateTime-Calendar-Mayan-[0-9]*:../../time/p5-DateTime-Calendar-Mayan
BUILD_DEPENDS+=	p5-DateTime-Format-MySQL-[0-9]*:../../time/p5-DateTime-Format-MySQL
BUILD_DEPENDS+=	p5-Declare-Constraints-Simple-[0-9]*:../../devel/p5-Declare-Constraints-Simple
BUILD_DEPENDS+=	p5-IO-String-[0-9]*:../../devel/p5-IO-String
BUILD_DEPENDS+=	p5-Locale-US-[0-9]*:../../misc/p5-Locale-US
BUILD_DEPENDS+=	p5-Module-Refresh-[0-9]*:../../devel/p5-Module-Refresh
BUILD_DEPENDS+=	p5-Params-Coerce-[0-9]*:../../devel/p5-Params-Coerce
BUILD_DEPENDS+=	p5-Regexp-Common-[0-9]*:../../textproc/p5-Regexp-Common
BUILD_DEPENDS+=	p5-Test-Deep-[0-9]*:../../devel/p5-Test-Deep
BUILD_DEPENDS+=	p5-Test-Warnings>=0.016:../../devel/p5-Test-Warnings

# other documented develop dependencies
BUILD_DEPENDS+=		p5-Algorithm-C3-[0-9]*:../../devel/p5-Algorithm-C3
BUILD_DEPENDS+=		p5-Test-CleanNamespaces>=0.13:../../devel/p5-Test-CleanNamespaces
# devel/p5-Data-Visitor depends on devel/p5-Moose
# BUILD_DEPENDS+=	p5-Data-Visitor-[0-9]*:../../devel/p5-Data-Visitor
BUILD_DEPENDS+=		p5-HTTP-Message-[0-9]*:../../www/p5-HTTP-Message
BUILD_DEPENDS+=		p5-PadWalker-[0-9]*:../../devel/p5-PadWalker
BUILD_DEPENDS+=		p5-SUPER-[0-9]*:../../devel/p5-SUPER
# missing Test::DependentModules>=0.13
BUILD_DEPENDS+=		p5-Test-Inline-[0-9]*:../../devel/p5-Test-Inline
BUILD_DEPENDS+=		p5-Test-LeakTrace-[0-9]*:../../devel/p5-Test-LeakTrace
BUILD_DEPENDS+=		p5-Test-Memory-Cycle-[0-9]*:../../devel/p5-Test-Memory-Cycle
BUILD_DEPENDS+=		p5-Test-Output-[0-9]*:../../devel/p5-Test-Output
BUILD_DEPENDS+=		p5-Test-CheckDeps>=0.006:../../devel/p5-Test-CheckDeps
BUILD_DEPENDS+=		p5-CPAN-Meta-Check>=0.007:../../devel/p5-CPAN-Meta-Check
# missing Test::Spelling
BUILD_DEPENDS+=		p5-URI-[0-9]*:../../www/p5-URI
#BUILD_DEPENDS+=	p5-Test-Pod-Coverage-[0-9]*:../../devel/p5-Test-Pod-Coverage # xt/author/pod_coverage.t
#BUILD_DEPENDS+=	p5-Test-Pod-[0-9]*:../../devel/p5-Test-Pod # xt/author/pod.t
#BUILD_DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI
#BUILD_DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww
# circular test dependency: p5-MetaCPAN-Client => p5-Type-Tiny => p5-Moose
# => p5-Test-DependentModules => p5-MetaCPAN-Client
#BUILD_DEPENDS+=	p5-Test-DependentModules-[0-9]*:../../devel/p5-Test-DependentModules

PERL5_PACKLIST=	auto/Moose/.packlist

PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
