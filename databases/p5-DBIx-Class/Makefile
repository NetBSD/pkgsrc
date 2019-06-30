# $NetBSD: Makefile,v 1.44 2019/06/30 20:14:23 nia Exp $

DISTNAME=	DBIx-Class-0.082841
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBIx/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/DBIx-Class
COMMENT=	Extensible and flexible object <-> relational mapper
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Class-Accessor-Grouped>=0.10012:../../devel/p5-Class-Accessor-Grouped
DEPENDS+=	p5-Class-C3-Componentised>=1.0009:../../devel/p5-Class-C3-Componentised
DEPENDS+=	p5-Class-Inspector>=1.24:../../devel/p5-Class-Inspector
DEPENDS+=	p5-Class-Method-Modifiers>=1.06:../../devel/p5-Class-Method-Modifiers
DEPENDS+=	p5-Config-Any>=0.20:../../devel/p5-Config-Any
DEPENDS+=	p5-Context-Preserve>=0.01:../../devel/p5-Context-Preserve
DEPENDS+=	p5-Data-Page>=2.00:../../devel/p5-Data-Page
DEPENDS+=	p5-Data-Compare>=1.22:../../devel/p5-Data-Compare
DEPENDS+=	p5-Data-Dumper-Concise>=2.020:../../devel/p5-Data-Dumper-Concise
DEPENDS+=	p5-Devel-GlobalDestruction>=0.09:../../devel/p5-Devel-GlobalDestruction
DEPENDS+=	p5-Hash-Merge>=0.12:../../devel/p5-Hash-Merge
DEPENDS+=	p5-MRO-Compat>=0.12:../../devel/p5-MRO-Compat
DEPENDS+=	p5-Module-Find>=0.07:../../devel/p5-Module-Find
DEPENDS+=	p5-Moo>=2.000:../../devel/p5-Moo
DEPENDS+=	p5-Path-Class>=0.18:../../devel/p5-Path-Class
DEPENDS+=	p5-SQL-Abstract>=1.81:../../databases/p5-SQL-Abstract
DEPENDS+=	p5-SQL-Abstract-Limit>=0.13:../../databases/p5-SQL-Abstract-Limit
DEPENDS+=	p5-Scope-Guard>=0.03:../../devel/p5-Scope-Guard
DEPENDS+=	p5-Sub-Name>=0.04:../../devel/p5-Sub-Name
DEPENDS+=	p5-Try-Tiny>=0.07:../../devel/p5-Try-Tiny
DEPENDS+=	p5-namespace-clean>=0.24:../../devel/p5-namespace-clean

BUILD_DEPENDS+=	p5-DBD-SQLite>=1.40:../../databases/p5-DBD-SQLite
BUILD_DEPENDS+= p5-Package-Stash>=0.28:../../devel/p5-Package-Stash
#BUILD_DEPENDS+=	{perl>=5.10.1,p5-File-Temp>=0.22}:../../devel/p5-File-Temp
BUILD_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception
#BUILD_DEPENDS+=	{perl>=5.10.1,p5-Test-Simple>=0.92}:../../devel/p5-Test-Simple
BUILD_DEPENDS+=	p5-Test-Warn>=0.21:../../devel/p5-Test-Warn
BUILD_DEPENDS+=	p5-Class-DBI>=0:../../databases/p5-Class-DBI
BUILD_DEPENDS+=	p5-SQL-Translator>=0.11018:../../databases/p5-SQL-Translator
# for make test
BUILD_DEPENDS+=	p5-Test-Deep-[0-9]*:../../devel/p5-Test-Deep

REPLACE_PERL=	script/dbicadmin

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/DBIx/Class/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

BUILDLINK_API_DEPENDS.p5-DBI+=	p5-DBI>=1.609

.include "../../databases/p5-DBI/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
