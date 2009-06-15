# $NetBSD: Makefile,v 1.10 2009/06/15 20:30:03 sno Exp $

DISTNAME=	DBIx-Class-0.08107
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBIx/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/DBIx-Class/
COMMENT=	Extensible and flexible object <-> relational mapper
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Carp-Clan>=6.0:../../devel/p5-Carp-Clan
DEPENDS+=	p5-Class-Accessor-Grouped>=0.08003:../../devel/p5-Class-Accessor-Grouped
DEPENDS+=	p5-Class-C3>=0.20:../../devel/p5-Class-C3
DEPENDS+=	p5-Class-C3-Componentised>=1.0005:../../devel/p5-Class-C3-Componentised
DEPENDS+=	p5-Class-Inspector>=1.24:../../devel/p5-Class-Inspector
DEPENDS+=	p5-DBD-SQLite>=1.25:../../databases/p5-DBD-SQLite
DEPENDS+=	p5-Data-Page>=2.00:../../devel/p5-Data-Page
DEPENDS+=	p5-JSON-Any>=1.18:../../converters/p5-JSON-Any
DEPENDS+=	p5-MRO-Compat>=0.09:../../devel/p5-MRO-Compat
DEPENDS+=	p5-Module-Find>=0.06:../../devel/p5-Module-Find
DEPENDS+=	p5-Path-Class>=0.16:../../devel/p5-Path-Class
DEPENDS+=	p5-SQL-Abstract>=1.56:../../databases/p5-SQL-Abstract
DEPENDS+=	p5-SQL-Abstract-Limit>=0.13:../../databases/p5-SQL-Abstract-Limit
DEPENDS+=	p5-Scope-Guard>=0.03:../../devel/p5-Scope-Guard
DEPENDS+=	{perl>=5.10,p5-Scalar-List-Utils>=1.19}:../../devel/p5-Scalar-List-Utils
DEPENDS+=	{perl>=5.10,p5-Storable-[0-9]*}:../../devel/p5-Storable
DEPENDS+=	p5-Sub-Name>=0.04:../../devel/p5-Sub-Name

BUILD_DEPENDS+=	p5-Test-Simple>=0.82:../../devel/p5-Test-Simple
BUILD_DEPENDS+=	p5-Test-Exception>=0:../../devel/p5-Test-Exception
BUILD_DEPENDS+=	p5-Test-Deep>=0:../../devel/p5-Test-Deep
BUILD_DEPENDS+=	p5-Test-Warn>=0.11:../../devel/p5-Test-Warn

PKG_DESTDIR_SUPPORT=	user-destdir

.include 	"options.mk"

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/DBIx/Class/.packlist
PERL5_MODULE_TYPE=	Module::Install

BUILDLINK_API_DEPENDS.p5-DBI+=	p5-DBI>=1.605

.include "../../databases/p5-DBI/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
