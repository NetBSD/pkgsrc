# $NetBSD: Makefile,v 1.57 2012/07/18 08:52:45 sno Exp $

DISTNAME=	Moose-2.0603
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://moose.perl.org/
COMMENT=	Postmodern object system for Perl 5
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Class-Load>=0.09:../../devel/p5-Class-Load
DEPENDS+=	p5-Class-Load-XS>=0.01:../../devel/p5-Class-Load-XS
DEPENDS+=	p5-Data-OptList>=0.107:../../devel/p5-Data-OptList
DEPENDS+=	p5-Devel-GlobalDestruction>=0:../../devel/p5-Devel-GlobalDestruction
DEPENDS+=	p5-Dist-CheckConflicts>=0.02:../../devel/p5-Dist-CheckConflicts
DEPENDS+=	p5-Eval-Closure>=0.04:../../devel/p5-Eval-Closure #XXX
DEPENDS+=	p5-List-MoreUtils>=0.28:../../devel/p5-List-MoreUtils
DEPENDS+=	p5-MRO-Compat>=0.05:../../devel/p5-MRO-Compat
DEPENDS+=	p5-Package-DeprecationManager>=0.11:../../devel/p5-Package-DeprecationManager
DEPENDS+=	p5-Package-Stash>=0.32:../../devel/p5-Package-Stash
DEPENDS+=	p5-Package-Stash-XS>=0.24:../../devel/p5-Package-Stash-XS
DEPENDS+=	p5-Params-Util>=1.00:../../devel/p5-Params-Util
DEPENDS+=	p5-Sub-Exporter>=0.980:../../devel/p5-Sub-Exporter
DEPENDS+=	p5-Sub-Name>=0.05:../../devel/p5-Sub-Name
DEPENDS+=	p5-Task-Weaken-[0-9]*:../../devel/p5-Task-Weaken
DEPENDS+=	p5-Try-Tiny>=0.02:../../devel/p5-Try-Tiny
# Note: Moose can take advantage of PartialDump, but as PartialDump depends
# on Moose, we cannot add it to DEPENDS

BUILD_DEPENDS+= p5-Test-Fatal>=0.05:../../devel/p5-Test-Fatal
BUILD_DEPENDS+= p5-Test-Requires>=0.05:../../devel/p5-Test-Requires

CONFLICTS+=	p5-Class-MOP-[0-9]*

# t/200_examples/002_example_Moose_POOP.t
BUILD_DEPENDS+= p5-DBM-Deep-[0-9]*:../../databases/p5-DBM-Deep
# t/000_recipes/moose_cookbook_basics_recipe11.t
BUILD_DEPENDS+= p5-DateTime-Calendar-Mayan-[0-9]*:../../time/p5-DateTime-Calendar-Mayan
# t/200_examples/002_example_Moose_POOP.t
BUILD_DEPENDS+= p5-DateTime-Format-MySQL-[0-9]*:../../time/p5-DateTime-Format-MySQL
# t/200_examples/00{4,5}_*
BUILD_DEPENDS+= p5-Declare-Constraints-Simple-[0-9]*:../../devel/p5-Declare-Constraints-Simple
# t/040_type_constraints/009_union_types_and_coercions.t
BUILD_DEPENDS+= p5-IO-String-[0-9]*:../../devel/p5-IO-String
# t/000_recipes/moose_cookbook_basics_recipe4.t
BUILD_DEPENDS+= p5-Locale-US-[0-9]*:../../misc/p5-Locale-US
# t/060_compat/001_module_refresh_compat.t
BUILD_DEPENDS+= p5-Module-Refresh-[0-9]*:../../devel/p5-Module-Refresh
# t/000_recipes/moose_cookbook_basics_recipe5.t
BUILD_DEPENDS+= p5-Params-Coerce-[0-9]*:../../devel/p5-Params-Coerce
# t/000_recipes/moose_cookbook_basics_recipe4.t
BUILD_DEPENDS+= p5-Regexp-Common-[0-9]*:../../textproc/p5-Regexp-Common
# t/200_examples/005_example_w_TestDeep.t
BUILD_DEPENDS+= p5-Test-Deep-[0-9]*:../../devel/p5-Test-Deep
# t/020_attributes/027_accessor_override_method.t
# t/050_metaclasses/012_moose_exporter.t
# t/300_immutable/011_constructor_is_wrapped.t
# t/300_immutable/010_constructor_is_not_moose.t
# t/300_immutable/013_immutable_roundtrip.t
# t/030_roles/019_build.t
# t/000_recipes/moose_cookbook_extending_recipe2.t

# other documented develop dependencies
BUILD_DEPENDS+=	p5-Algorithm-C3-[0-9]*:../../devel/p5-Algorithm-C3
# devel/p5-Data-Visitor depends on devel/p5-Moose
# BUILD_DEPENDS+=	p5-Data-Visitor-[0-9]*:../../devel/p5-Data-Visitor
BUILD_DEPENDS+=	p5-HTTP-Message-[0-9]*:../../www/p5-HTTP-Message
BUILD_DEPENDS+=	p5-PadWalker-[0-9]*:../../devel/p5-PadWalker
BUILD_DEPENDS+=	p5-SUPER-[0-9]*:../../devel/p5-SUPER
# missing Test::DependentModules>=0.13
BUILD_DEPENDS+=	p5-Test-Inline-[0-9]*:../../devel/p5-Test-Inline
BUILD_DEPENDS+=	p5-Test-LeakTrace-[0-9]*:../../devel/p5-Test-LeakTrace
BUILD_DEPENDS+=	p5-Test-Memory-Cycle-[0-9]*:../../devel/p5-Test-Memory-Cycle
BUILD_DEPENDS+= p5-Test-Output-[0-9]*:../../devel/p5-Test-Output
# missing Test::Spelling
BUILD_DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI
#BUILD_DEPENDS+=	p5-Test-Pod-Coverage-[0-9]*:../../devel/p5-Test-Pod-Coverage # xt/author/pod_coverage.t
#BUILD_DEPENDS+=	p5-Test-Pod-[0-9]*:../../devel/p5-Test-Pod # xt/author/pod.t
#BUILD_DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI
#BUILD_DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww

USE_LANGUAGES=		c
USE_TOOLS+=		gmake

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST= auto/Moose/.packlist

PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
