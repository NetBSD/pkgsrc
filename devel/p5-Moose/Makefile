# $NetBSD: Makefile,v 1.51 2011/08/14 12:26:20 obache Exp $
#

DISTNAME=	Moose-1.14
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://moose.perl.org/
COMMENT=	Postmodern object system for Perl 5
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Class-MOP>=1.05:../../devel/p5-Class-MOP
DEPENDS+=	p5-Data-OptList-[0-9]*:../../devel/p5-Data-OptList
DEPENDS+=	p5-List-MoreUtils>=0.12:../../devel/p5-List-MoreUtils
DEPENDS+=	p5-Package-DeprecationManager>=0.04:../../devel/p5-Package-DeprecationManager
DEPENDS+=	p5-Sub-Exporter>=0.980:../../devel/p5-Sub-Exporter
DEPENDS+=	p5-Sub-Name-[0-9]*:../../devel/p5-Sub-Name
DEPENDS+=	p5-Task-Weaken-[0-9]*:../../devel/p5-Task-Weaken
DEPENDS+=	p5-Try-Tiny>=0.02:../../devel/p5-Try-Tiny

BUILD_DEPENDS+=	p5-Test-Exception>=0.27:../../devel/p5-Test-Exception
BUILD_DEPENDS+=	p5-Test-Requires>=0.05:../../devel/p5-Test-Requires

# t/200_examples/002_example_Moose_POOP.t
BUILD_DEPENDS+=	p5-DBM-Deep-[0-9]*:../../databases/p5-DBM-Deep
# t/000_recipes/moose_cookbook_basics_recipe11.t
BUILD_DEPENDS+=	p5-DateTime-Calendar-Mayan-[0-9]*:../../time/p5-DateTime-Calendar-Mayan
# t/200_examples/002_example_Moose_POOP.t
BUILD_DEPENDS+=	p5-DateTime-Format-MySQL-[0-9]*:../../time/p5-DateTime-Format-MySQL
# t/200_examples/00{4,5}_*
BUILD_DEPENDS+=	p5-Declare-Constraints-Simple-[0-9]*:../../devel/p5-Declare-Constraints-Simple
# t/040_type_constraints/009_union_types_and_coercions.t
BUILD_DEPENDS+=	p5-IO-String-[0-9]*:../../devel/p5-IO-String
# t/000_recipes/moose_cookbook_basics_recipe4.t
BUILD_DEPENDS+=	p5-Locale-US-[0-9]*:../../misc/p5-Locale-US
# t/060_compat/001_module_refresh_compat.t
BUILD_DEPENDS+=	p5-Module-Refresh-[0-9]*:../../devel/p5-Module-Refresh
# t/000_recipes/moose_cookbook_basics_recipe5.t
BUILD_DEPENDS+=	p5-Params-Coerce-[0-9]*:../../devel/p5-Params-Coerce
# t/000_recipes/moose_cookbook_basics_recipe4.t
BUILD_DEPENDS+=	p5-Regexp-Common-[0-9]*:../../textproc/p5-Regexp-Common
# t/200_examples/005_example_w_TestDeep.t
BUILD_DEPENDS+=	p5-Test-Deep-[0-9]*:../../devel/p5-Test-Deep
# t/020_attributes/027_accessor_override_method.t
# t/050_metaclasses/012_moose_exporter.t
# t/300_immutable/011_constructor_is_wrapped.t
# t/300_immutable/010_constructor_is_not_moose.t
# t/300_immutable/013_immutable_roundtrip.t
# t/030_roles/019_build.t
# t/000_recipes/moose_cookbook_extending_recipe2.t
BUILD_DEPENDS+=	p5-Test-Output-[0-9]*:../../devel/p5-Test-Output
#BUILD_DEPENDS+=	p5-Test-Pod-Coverage-[0-9]*:../../devel/p5-Test-Pod-Coverage # xt/author/pod_coverage.t
#BUILD_DEPENDS+=	p5-Test-Pod-[0-9]*:../../devel/p5-Test-Pod # xt/author/pod.t
#BUILD_DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI
#BUILD_DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Moose/.packlist

PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
