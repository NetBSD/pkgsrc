# $NetBSD: Makefile,v 1.1.1.1 2008/07/15 08:41:32 abs Exp $

DISTNAME=	DBIx-Class-0.08010
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBIx/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/DBIx-Class/
COMMENT=	Extensible and flexible object <-> relational mapper

DEPENDS+=	p5-Data-Page>=2.00:../../devel/p5-Data-Page
DEPENDS+=	p5-Scalar-List-Utils>=0:../../devel/p5-Scalar-List-Utils
DEPENDS+=	p5-SQL-Abstract>=1.20:../../databases/p5-SQL-Abstract
DEPENDS+=	p5-SQL-Abstract-Limit>=0.11:../../databases/p5-SQL-Abstract-Limit
DEPENDS+=	p5-Class-C3>=0.13:../../devel/p5-Class-C3
DEPENDS+=	p5-Class-C3-Componentised>=0:../../devel/p5-Class-C3-Componentised
DEPENDS+=	p5-Storable>=0:../../devel/p5-Storable
DEPENDS+=	p5-Class-Data-Accessor>=0.01:../../devel/p5-Class-Data-Accessor
DEPENDS+=	p5-Carp-Clan>=0:../../devel/p5-Carp-Clan
DEPENDS+=	p5-DBI>=1.40:../../databases/p5-DBI
BUILD_DEPENDS+=	p5-DBD-SQLite>=1.11:../../databases/p5-DBD-SQLite
#DEPENDS+=	p5-Data-UUID>=0:../../devel/p5-Data-UUID
DEPENDS+=	p5-Module-Find>=0:../../devel/p5-Module-Find
DEPENDS+=	p5-Class-Accessor-Grouped>=0.5002:../../devel/p5-Class-Accessor-Grouped
DEPENDS+=	p5-Class-Inspector>=0:../../devel/p5-Class-Inspector
DEPENDS+=	p5-JSON-Any>=1.00:../../converters/p5-JSON-Any
DEPENDS+=	p5-Scope-Guard>=0.03:../../devel/p5-Scope-Guard

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/DBIx/Class/.packlist

PKG_DESTDIR_SUPPORT=    user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
