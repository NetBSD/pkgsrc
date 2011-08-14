# $NetBSD: Makefile,v 1.21 2011/08/14 08:18:06 obache Exp $

DISTNAME=	DBIx-Class-0.08123
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBIx/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/DBIx-Class/
COMMENT=	Extensible and flexible object <-> relational mapper
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Carp-Clan>=6.0:../../devel/p5-Carp-Clan
DEPENDS+=	p5-Class-Accessor-Grouped>=0.09003:../../devel/p5-Class-Accessor-Grouped
DEPENDS+=	p5-Class-C3-Componentised>=1.0005:../../devel/p5-Class-C3-Componentised
DEPENDS+=	p5-Class-Inspector>=1.24:../../devel/p5-Class-Inspector
DEPENDS+=	p5-Context-Preserve>=0.01:../../devel/p5-Context-Preserve
DEPENDS+=	p5-DBD-SQLite>=1.25:../../databases/p5-DBD-SQLite
DEPENDS+=	p5-Data-Page>=2.00:../../devel/p5-Data-Page
DEPENDS+=	p5-Data-Dumper-Concise>=1.000:../../devel/p5-Data-Dumper-Concise
DEPENDS+=	p5-MRO-Compat>=0.09:../../devel/p5-MRO-Compat
DEPENDS+=	p5-Math-Base36>=0.07:../../math/p5-Math-Base36
DEPENDS+=	p5-Module-Find>=0.06:../../devel/p5-Module-Find
DEPENDS+=	p5-Path-Class>=0.18:../../devel/p5-Path-Class
DEPENDS+=	p5-SQL-Abstract>=1.67:../../databases/p5-SQL-Abstract
DEPENDS+=	p5-SQL-Abstract-Limit>=0.13:../../databases/p5-SQL-Abstract-Limit
DEPENDS+=	p5-Scope-Guard>=0.03:../../devel/p5-Scope-Guard
DEPENDS+=	p5-Sub-Name>=0.04:../../devel/p5-Sub-Name
DEPENDS+=	p5-Try-Tiny>=0.04:../../devel/p5-Try-Tiny
DEPENDS+=	p5-namespace-clean>=0.14:../../devel/p5-namespace-clean

BUILD_DEPENDS+=	{perl>=5.10.1,p5-File-Temp>=0.22}:../../devel/p5-File-Temp
BUILD_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception
BUILD_DEPENDS+=	{perl>=5.10.1,p5-Test-Simple>=0.92}:../../devel/p5-Test-Simple
BUILD_DEPENDS+=	p5-Test-Warn>=0.21:../../devel/p5-Test-Warn

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/DBIx/Class/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

BUILDLINK_API_DEPENDS.p5-DBI+=	p5-DBI>=1.609

.include "../../databases/p5-DBI/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
