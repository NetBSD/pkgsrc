# $NetBSD: Makefile,v 1.4 2009/04/10 09:48:06 abs Exp $

DISTNAME=	DBIx-Class-0.08013
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBIx/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/DBIx-Class/
COMMENT=	Extensible and flexible object <-> relational mapper

DEPENDS+=	p5-Data-Page>=2.00:../../devel/p5-Data-Page
DEPENDS+=	p5-Scalar-List-Utils>=1.19:../../devel/p5-Scalar-List-Utils
DEPENDS+=	p5-SQL-Abstract>=1.51:../../databases/p5-SQL-Abstract
DEPENDS+=	p5-SQL-Abstract-Limit>=0.13:../../databases/p5-SQL-Abstract-Limit
DEPENDS+=	p5-Class-C3>=0.20:../../devel/p5-Class-C3
DEPENDS+=	p5-Class-C3-Componentised>=1.0004:../../devel/p5-Class-C3-Componentised
DEPENDS+=	p5-Storable>=0:../../devel/p5-Storable
DEPENDS+=	p5-Carp-Clan>=0:../../devel/p5-Carp-Clan
DEPENDS+=	p5-DBI>=1.40:../../databases/p5-DBI
DEPENDS+=	p5-Module-Find>=0:../../devel/p5-Module-Find

DEPENDS+=	p5-Class-Inspector>=0:../../devel/p5-Class-Inspector
DEPENDS+=	p5-Class-Accessor-Grouped>=0.08003:../../devel/p5-Class-Accessor-Grouped
DEPENDS+=	p5-JSON-Any>=1.17:../../converters/p5-JSON-Any
DEPENDS+=	p5-Scope-Guard>=0.03:../../devel/p5-Scope-Guard

BUILD_DEPENDS+=	p5-DBD-SQLite>=1.14:../../databases/p5-DBD-SQLite
BUILD_DEPENDS+=	p5-Test-Simple>=0.33:../../devel/p5-Test-Simple
BUILD_DEPENDS+=	p5-Test-Exception>=0:../../devel/p5-Test-Exception
BUILD_DEPENDS+=	p5-Test-Deep>=0:../../devel/p5-Test-Deep

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/DBIx/Class/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
